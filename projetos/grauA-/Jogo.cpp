#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(1280, 720, false);

	srand(time(NULL));

	//	O resto da inicialização vem aqui!
	//	...
	carregarAssets();

	tela = telaMenu;
	jogador = nullptr;

	bgX = 0;
	bgParalaxX = 0;

	bg1.setSpriteSheet("bg");
	bg2.setSpriteSheet("bg");
	bgParalax1.setSpriteSheet("bgParalax");
	bgParalax2.setSpriteSheet("bgParalax");

//	for (int i = 0; i < 100; i++)
	{
//		meteoros[i] = nullptr;
	}
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...

	uniFinalizar();
}

void Jogo::executar()
{
	while (!gEventos.sair)
	{
		uniIniciarFrame();

		//	Seu código vem aqui!
		//	...
		background();

		switch (tela)
		{
		case telaMenu:
			executarTelaMenu();
			break;
		case telaJogo:
			executarTelaJogo();
			break;
		case telaGameOver:
			executarTelaGameOver();
			break;
		}
		uniTerminarFrame();
	}
}

void Jogo::carregarAssets()
{
	string tipo, nome, caminho;
	int tamanho, animacoes, frames;

	ifstream carregarAssets("assets\\loader.txt");

	if (carregarAssets.is_open())
	{
		while (!carregarAssets.eof())
		{
			carregarAssets >> tipo;
			if (tipo == "audio")
			{
				carregarAssets >> nome >> caminho;
				if (!gRecursos.carregouAudio(nome))
				{
					gRecursos.carregarAudio(nome, caminho);
				}
			}
			else if (tipo == "fonte")
			{
				carregarAssets >> nome >> caminho >> tamanho;
				if (!gRecursos.carregouFonte(nome))
				{
					gRecursos.carregarFonte(nome, caminho, tamanho);
				}
			}
			else if (tipo == "musica")
			{
				carregarAssets >> nome >> caminho;
				if (!gRecursos.carregouMusica(nome))
				{
					gRecursos.carregarMusica(nome, caminho);
				}
			}
			else if (tipo == "sprite")
			{
				carregarAssets >> nome >> caminho >> animacoes >> frames;
				if (!gRecursos.carregouSpriteSheet(nome))
				{
					gRecursos.carregarSpriteSheet(nome, caminho, animacoes, frames);
				}
			}
		}
	}
	else
	{
		cout << "Erro ao carregar assets.";
	}
}

void Jogo::criarMeteoro()
{
	if ((cdMeteoro % 300) == 0)
	{
		meteoros[indexMeteoro] = new Meteoro();
		indexMeteoro++;
	}

	if ((rand() % 1000) == 0)
	{
		meteoros[indexMeteoro] = new Meteoro();
		indexMeteoro++;
	}

	cdMeteoro++;
}

void Jogo::colisaoMeteoroTiro()
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int k = 0; k < 100; k++)
			{
				if (jogador->getNave(j)->getTiro(i) != nullptr && meteoros[k] != nullptr)
				{
					if (uniTestarColisaoCirculoComCirculo(jogador->getNave(j)->getTiro(i)->getX(), jogador->getNave(j)->getTiro(i)->getY(), (jogador->getNave(j)->getTiro(i)->getSprite().getAltura() / 2), meteoros[k]->getX(), meteoros[k]->getY(), (meteoros[k]->getSprite().getAltura() / 2)))
					{
						if (jogador->getNave(j)->getTiro(i)->getCor() == meteoros[k]->getCor())
						{
							delete jogador->getNave(j)->getTiro(i);
							jogador->getNave(j)->setTiroNull(i);

							delete meteoros[k];
							meteoros[k] = nullptr;
						}
						else
						{
							delete jogador->getNave(j)->getTiro(i);
							jogador->getNave(j)->setTiroNull(i);
						}
					}
				}
			}
		}
	}
}

void Jogo::colisaoMeteoroNave()
{
	for (int k = 0; k < 100; k++)
	{
		if (meteoros[k] != nullptr)
		{
			if (uniTestarColisaoCirculoComCirculo(jogador->getX(), jogador->getY(), (jogador->getSprite().getAltura() / 2), meteoros[k]->getX(), meteoros[k]->getY(), (meteoros[k]->getSprite().getAltura() / 2)))
			{
				//Game Over

				delete meteoros[k];
				meteoros[k] = nullptr;
			}
		}
	}
}

void Jogo::resetar()
{
	if (jogador != nullptr)
	{
		delete jogador;
	}	
	jogador = new Jogador();
	jogador->inicializar();

	cdMeteoro = 0;
	indexMeteoro = 0;

	for (int i = 0; i < 100; i++)
	{
		meteoros[i] = nullptr;
	}
}

void Jogo::executarTelaMenu()
{
	if (gTeclado.pressionou[TECLA_ESPACO])
	{
		tela = telaJogo;
		resetar();
	}
}

void Jogo::executarTelaJogo()
{
	if (gTeclado.pressionou[TECLA_ESC])
	{
		tela = telaMenu;
	}
	// Jogador atualizar
	jogador->atualizar();
	jogador->desenhar();

	// Meteoro atualizar
	for (int i = 0; i < 100; i++)
	{
		if (meteoros[i] != nullptr)
		{
			meteoros[i]->atualizar();
			meteoros[i]->desenhar();
		}
	}
	criarMeteoro();

	// Colisão Meteoro <> Tiro
	colisaoMeteoroTiro();

	// Colisão Meteoro <> Nave
	colisaoMeteoroNave();
}

void Jogo::executarTelaGameOver()
{
}

void Jogo::background()
{
	if (bgX <= -gJanela.getLargura() / 2)
	{
		bgX = gJanela.getLargura() / 2;
	}
	if (bgParalaxX <= -gJanela.getLargura() / 2)
	{
		bgParalaxX = gJanela.getLargura() / 2;
	}

	bg1.desenhar(bgX, gJanela.getAltura() / 2);
	bg2.desenhar(bgX + gJanela.getLargura(), gJanela.getAltura() / 2);
	bgParalax1.desenhar(bgParalaxX, gJanela.getAltura() / 2);
	bgParalax2.desenhar(bgParalaxX + gJanela.getLargura(), gJanela.getAltura() / 2);

	bgX -= 0.1;
	bgParalaxX -= 0.2;
}
