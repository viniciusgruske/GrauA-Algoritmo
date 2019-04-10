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
	naveAtual = 0;
	velocidade = 3;
}

void Jogador::atualizar()
{
	if (gTeclado.segurando[TECLA_CIMA] && y > (naves[naveAtual]->getSprite().getAltura() / 2))
	{
		y -= velocidade;
	}
	if (gTeclado.segurando[TECLA_ESQ] && x > (naves[naveAtual]->getSprite().getLargura() / 2))
	{
		x -= velocidade;
	}
	if (gTeclado.segurando[TECLA_BAIXO] && y < (gJanela.getAltura() - (naves[naveAtual]->getSprite().getAltura() / 2)))
	{
		y += velocidade;
	}
	if (gTeclado.segurando[TECLA_DIR] && x < (gJanela.getLargura() - (naves[naveAtual]->getSprite().getLargura() / 2)))
	{
		x += velocidade;
	}
	if (gTeclado.pressionou[TECLA_Q])
	{
		naveAtual = 0;
	}
	if (gTeclado.pressionou[TECLA_W])
	{
		naveAtual = 1;
	}
	if (gTeclado.pressionou[TECLA_E])
	{
		naveAtual = 2;
	}
	if (gTeclado.pressionou[TECLA_ESPACO])
	{
		naves[naveAtual]->atirar();
	}
}

void Jogador::desenhar()
{
	naves[naveAtual]->desenhar(x, y);
}
