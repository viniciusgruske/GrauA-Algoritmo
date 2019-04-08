#include "Nave.h"

Nave::Nave()
{
}


Nave::~Nave()
{
}

void Nave::inicializar()
{
	naveAtual = 0;
	naves[0] = (Nave *) new NaveVermelha();
	naves[1] = (Nave *) new NaveVerde();
	naves[2] = (Nave *) new NaveAzul();

	naves[0]->inicializar();
}

void Nave::atualizar()
{
	if (gTeclado.segurando[TECLA_W])
	{
		x--;
	}
	if (gTeclado.segurando[TECLA_A])
	{
		y--;
	}
	if (gTeclado.segurando[TECLA_S])
	{
		x++;
	}
	if (gTeclado.segurando[TECLA_D])
	{
		y++;
	}
}

void Nave::desenhar()
{
	naves[naveAtual]->getSprite().desenhar(x, y);
}

Sprite Nave::getSprite()
{
	return naves[naveAtual]->getSprite();
}
