#include "Jogador.h"

Jogador::Jogador()
{
	inicializar();
}


Jogador::~Jogador()
{
}

void Jogador::inicializar()
{
	naves[0] = (Nave *) new NaveVermelha();
	naves[1] = (Nave *) new NaveVerde();
	naves[2] = (Nave *) new NaveAzul();

	x = 300;
	y = 200;
	cdTiro = 0;
	naveAtual = Vermelha;
	velocidade = 3;
}

void Jogador::atualizar()
{
	if (gTeclado.segurando[TECLA_CIMA] && y > (naves[naveAtual]->getSprite().getAltura() / 2))
	{
		y -= velocidade;
		naves[naveAtual]->setSpriteCima();
	}
	if (gTeclado.segurando[TECLA_ESQ] && x > (naves[naveAtual]->getSprite().getLargura() / 2))
	{
		x -= velocidade;
	}
	if (gTeclado.segurando[TECLA_BAIXO] && y < (gJanela.getAltura() - (naves[naveAtual]->getSprite().getAltura() / 2)))
	{
		y += velocidade;
		naves[naveAtual]->setSpriteBaixo();
	}
	if (gTeclado.segurando[TECLA_DIR] && x < (gJanela.getLargura() - (naves[naveAtual]->getSprite().getLargura() / 2)))
	{
		x += velocidade;
	}
	if (gTeclado.segurando[TECLA_CIMA] && gTeclado.segurando[TECLA_BAIXO])
	{
		naves[naveAtual]->setSpriteDefault();
	}
	if (gTeclado.soltou[TECLA_CIMA] || gTeclado.soltou[TECLA_BAIXO])
	{
		naves[naveAtual]->setSpriteDefault();
	}
	if (gTeclado.pressionou[TECLA_Q])
	{
		naveAtual = Vermelha;
	}
	if (gTeclado.pressionou[TECLA_W])
	{
		naveAtual = Verde;
	}
	if (gTeclado.pressionou[TECLA_E])
	{
		naveAtual = Azul;
	}
	if (gTeclado.segurando[TECLA_ESPACO])
	{
		if ((cdTiro % 20) == 0)
		{
			naves[naveAtual]->atirar(x, y, naveAtual);
		}
	}
	cdTiro++;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			if (naves[j]->getTiro(i) != nullptr)
			{
				naves[j]->getTiro(i)->atualizar();
			}
		}
	}
}

void Jogador::desenhar()
{
	naves[naveAtual]->desenhar(x, y);

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			if (naves[j]->getTiro(i) != nullptr)
			{
				naves[j]->getTiro(i)->desenhar();
			}
		}
	}
}
