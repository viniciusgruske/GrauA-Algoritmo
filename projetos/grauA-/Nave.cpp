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
}

void Nave::atualizar()
{
}

void Nave::desenhar(float x, float y)
{
	getSprite().desenhar(x, y);
}

Sprite Nave::getSprite()
{
	return sprite;
}



