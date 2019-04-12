#include "Tiro.h"

Tiro::Tiro(float x, float y, Cores c)
{
	this->x = x;
	this->y = y;
	cor = c;
	velocidade = 5;

	if (c == Vermelha)
	{
		sprite.setSpriteSheet("tiroVermelho");
	}
	else if (c == Verde)
	{
		sprite.setSpriteSheet("tiroVerde");
	}
	else if (c == Azul)
	{
		sprite.setSpriteSheet("tiroAzul");
	}
}

Tiro::~Tiro()
{
}

void Tiro::atualizar()
{
	y -= velocidade;
}

void Tiro::desenhar()
{
	sprite.desenhar(x, y);
}
