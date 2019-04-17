#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	srand(time(NULL));

	//	O resto da inicialização vem aqui!
	//	...
	carregarAssets();
	jogador = new Jogador();
	jogador->inicializar();

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

		jogador->atualizar();
		jogador->desenhar();

		if (meteoros[0] != nullptr)
		{
			meteoros[0]->atualizar();
			meteoros[0]->desenhar();
		} 

		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				if (jogador->getNave(j)->getTiro(i) != nullptr && meteoros[0] != nullptr)
				{
					if (uniTestarColisaoCirculoComCirculo(jogador->getNave(j)->getTiro(i)->getX(), jogador->getNave(j)->getTiro(i)->getY(), (jogador->getNave(j)->getTiro(i)->getSprite().getAltura() / 2), meteoros[0]->getX(), meteoros[0]->getY(), (meteoros[0]->getSprite().getAltura() / 2)))
					{
						if (jogador->getNave(j)->getTiro(i)->getCor() == meteoros[0]->getCor())
						{
							
							//meteoros[0] = nullptr;
							//meteoros[0]->~Meteoro();
							delete jogador->getNave(j)->getTiro(i);
							jogador->getNave(j)->setTiroNull(i);

							delete meteoros[0];
							meteoros[0] = nullptr;
						}
					}
				}
			}
		}

		uniTerminarFrame();
	}
}

void Jogo::carregarAssets()
{
	ifstream carregarAssets("assets/loader.txt");

	string tipo, nome, caminho;
	int tamanho, animacoes, frames;

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
