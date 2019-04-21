#pragma once
#include "libUnicornio.h"

enum Cores { Vermelha, Verde, Azul };

class Tiro
{
public:
	Tiro(float x, float y, Cores c);
	~Tiro();

	void atualizar();
	void desenhar();

	Cores getCor() { return cor; }
	float getX() { return x; }
	float getY() { return y; }
	Sprite getSprite() { return sprite; }

private:
	float x, y, velocidade;
	Cores cor;
	Sprite sprite;
};