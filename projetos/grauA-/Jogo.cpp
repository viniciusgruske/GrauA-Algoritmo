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

	cdMeteoro = 0;
	indexMeteoro = 0;

	jogador = new Jogador();
	jogador->inicializar();

	for (int i = 0; i < 100; i++)
	{
		meteoros[i] = nullptr;
	}

	meteoros[0] = new Meteoro();
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...

	uniFinalizar();
}

void Jogo::executar()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		//	Seu código vem aqui!
		//	...

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
	if ((cdMeteoro % 100) == 0)
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
