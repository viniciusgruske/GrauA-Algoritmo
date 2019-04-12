#include "Nave.h"

Nave::Nave()
{
	inicializar();
}


Nave::~Nave()
{
}

void Nave::inicializar()
{
	indexTiro = 0;
	for (int i = 0; i < 20; i++)
	{
		tiro[i] = nullptr;
	}
}

void Nave::desenhar(float x, float y)
{
	getSprite().desenhar(x, y);
}

Sprite Nave::getSprite()
{
	return sprite;
}

void Nave::atirar(float x, float y, Cores c)
{
	if (indexTiro > 19)
	{
		indexTiro = 0;
	}
	else
	{
		indexTiro++;
	}

	tiro[indexTiro] = new Tiro(x, y, c);
}



