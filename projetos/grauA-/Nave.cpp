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
	for (int i = 0; i < 10; i++)
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

void Nave::setSpriteDefault()
{
}

void Nave::setSpriteEsquerda()
{
}

void Nave::setSpriteDireita()
{
}

void Nave::atirar(float x, float y, Cores c)
{
	delete tiro[indexTiro];

	tiro[indexTiro] = new Tiro(x, y, c);

	if (indexTiro >= 9)
	{
        indexTiro = 0;
	}
	else
	{
		indexTiro++;
	}
}



