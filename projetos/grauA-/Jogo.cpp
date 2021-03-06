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

	//	O resto da inicializa��o vem aqui!
	//	...
	carregarAssets();

	tela = telaMenu;
	jogador = nullptr;
	dificuldade = 1;
	cdDificuldade = 0;

	bgX = 0;
	bgParalaxX = 0;
	bgParalax = true;

	bg1.setSpriteSheet("bg");
	bg2.setSpriteSheet("bg");
	bgParalax1.setSpriteSheet("bgParalax");
	bgParalax2.setSpriteSheet("bgParalax");
	pause.setSpriteSheet("pause");

	vidas.setSpriteSheet("naveVermelha");
	vidas.setAncora(0.5, 0);
	vidas.setEscala(0.5, 0.5);

	level.setAncora(0, 0.5);
	level.setCor(255, 255, 255);
	level.setFonte("fonte16");

	botaoJogar.setSpriteSheet("botaoJogar");
	botaoJogar.setPos(gJanela.getLargura() / 2, 400);

	botaoVoltar.setSpriteSheet("botaoVoltar");
	botaoVoltar.setPos(gJanela.getLargura() / 2, 600);

	botaoSair.setSpriteSheet("botaoSair");
	botaoSair.setPos(gJanela.getLargura() / 2, 600);

	//	for (int i = 0; i < 100; i++)
	//	{
	//		meteoros[i] = nullptr;
	//	}
}

void Jogo::finalizar()
{
	//	O resto da finaliza��o vem aqui (provavelmente, em ordem inversa a inicializa��o)!
	//	...

	uniFinalizar();
}

void Jogo::executar()
{
	while (!gEventos.sair && tela != sair)
	{
		uniIniciarFrame();

		//	Seu c�digo vem aqui!
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
		case telaPause:
			executarTelaPause();
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
			else if (tipo == "botao")
			{
				carregarAssets >> nome >> caminho >> animacoes;
				if (!gRecursos.carregouSpriteSheet(nome))
				{
					gRecursos.carregarSpriteSheet(nome, caminho, animacoes);
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
	if ((cdMeteoro % 303 - (dificuldade * 3)) == 0)
	{
		meteoros[indexMeteoro] = new Meteoro(dificuldade);
		//meteoros->push_back(*new Meteoro);

		if (indexMeteoro >= 99)
		{
			indexMeteoro = 0;
		}
		else
		{
			indexMeteoro++;
		}
	}
	if ((rand() % 1010 - (dificuldade * 10)) == 0)
	{
		meteoros[indexMeteoro] = new Meteoro(dificuldade);
		//meteoros->push_back(*new Meteoro);

		if (indexMeteoro >= 99)
		{
			indexMeteoro = 0;
		}
		else
		{
			indexMeteoro++;
		}
	}
	cdMeteoro++;
}

void Jogo::criarMeteoroColisao(int i, Cores c, float x, float y, float e, float vX)
{
	for (int j = 0; j < i; j++)
	{
		meteoros[indexMeteoro] = new Meteoro(c, x, y, e, vX);
		//meteoros->push_back(*new Meteoro(c, x, y, e, vX));

	/*	if (indexMeteoro >= 99)
		{
			indexMeteoro = 0;
		}
		else
		{
			indexMeteoro++;
		}*/
	}
}

void Jogo::colisaoMeteoroTiro()
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int k = 0; k < 100; k++)
				//for (int k = 0; k < meteoros->size(); k++)
			{
				if (jogador->getNave(j)->getTiro(i) != nullptr && meteoros[k] != nullptr)
					//if (jogador->getNave(j)->getTiro(i) != nullptr)
				{
					if (uniTestarColisaoCirculoComCirculo(jogador->getNave(j)->getTiro(i)->getX(), jogador->getNave(j)->getTiro(i)->getY(), (jogador->getNave(j)->getTiro(i)->getSprite().getAltura() / 2), meteoros[k]->getX(), meteoros[k]->getY(), (meteoros[k]->getSprite().getAltura() / 2)))
					{
						if (jogador->getNave(j)->getTiro(i)->getCor() == meteoros[k]->getCor())
						{
							delete jogador->getNave(j)->getTiro(i);
							jogador->getNave(j)->setTiroNull(i);

							if (meteoros[k]->getSprite().getEscalaX() == 1)
							{
								criarMeteoroColisao(2, meteoros[k]->getCor(), meteoros[k]->getX(), meteoros[k]->getY(), 0.75, meteoros[k]->getVelocidadeX());
								delete meteoros[k];
								meteoros[k] = nullptr;
							}
							else if (meteoros[k]->getSprite().getEscalaX() == 0.75)
							{
								criarMeteoroColisao(2, meteoros[k]->getCor(), meteoros[k]->getX(), meteoros[k]->getY(), 0.5, meteoros[k]->getVelocidadeX());
								delete meteoros[k];
								meteoros[k] = nullptr;
							}
							else
							{
								delete meteoros[k];
								meteoros[k] = nullptr;
							}
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
				jogador->setVida(-1);
				jogador->setX(gJanela.getLargura() / 4);
				jogador->setY(gJanela.getAltura() / 2);

				delete meteoros[k];
				meteoros[k] = nullptr;
			}
		}
	}
}

void Jogo::controlarDificuldade()
{
	cdDificuldade++;
	if (cdDificuldade >= 600)
	{
		dificuldade++;
		cdDificuldade = 0;
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
	dificuldade = 1;
	cdDificuldade = 0;

	for (int i = 0; i < 100; i++)
	{
		meteoros[i] = nullptr;
	}
}

void Jogo::executarTelaMenu()
{
	botaoJogar.desenhar();
	botaoJogar.atualizar();

	botaoSair.desenhar();
	botaoSair.atualizar();

	if (botaoJogar.estaClicado())
	{
		tela = telaJogo;
		resetar();
	}

	if (botaoSair.estaClicado())
	{
		tela = sair;
	}
}

void Jogo::executarTelaJogo()
{
	if (gTeclado.pressionou[TECLA_ESC])
	{
		tela = telaPause;
		bgParalax = false;
	}

	if (jogador->getVida() <= 0)
	{
		tela = telaGameOver;
	}

	if (dificuldade == 100)
	{
		tela = telaGameOver;
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

	for (int i = 0; i < jogador->getVida(); i++)
	{
		vidas.desenhar(40 + (i * 40), 680, -90);
	}

	level.setString("LEVEL " + to_string(dificuldade));
	level.desenhar(40, 640);

	controlarDificuldade();

	criarMeteoro();

	// Colis�o Meteoro <> Tiro
	colisaoMeteoroTiro();

	// Colis�o Meteoro <> Nave
	colisaoMeteoroNave();
}

void Jogo::executarTelaGameOver()
{
}

void Jogo::executarTelaPause()
{
	if (gTeclado.pressionou[TECLA_ESC])
	{
		tela = telaJogo;
		bgParalax = true;
	}

	jogador->desenhar();

	for (int i = 0; i < 100; i++)
	{
		if (meteoros[i] != nullptr)
		{
			meteoros[i]->desenhar();
		}
	}

	pause.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	botaoSair.desenhar();
	if (botaoSair.estaClicado())
	{
		tela = telaGameOver;
	}
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

	if (bgParalax)
	{
		bgX -= .1 * (0.9 + dificuldade / 10);
		bgParalaxX -= .2 * (0.9 + dificuldade / 10);
	}
}
