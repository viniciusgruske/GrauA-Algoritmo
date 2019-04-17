#pragma once
#include "libUnicornio.h"
#include "Tiro.h"

class Meteoro
{
public:
	Meteoro();
	~Meteoro();

	void inicializar();
	void atualizar();
	void desenhar();

	Cores getCor() { return cor; }
	float getX() { return x; }
	float getY() { return y; }
	Sprite getSprite() { return sprite; }

private:
	float x, y, velocidade;
	Sprite sprite;
	Cores cor;
	int seed;
};

