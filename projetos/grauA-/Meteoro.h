#pragma once
#include "libUnicornio.h"
#include "Tiro.h"

class Meteoro
{
public:
	Meteoro(float vX);
	Meteoro(Cores c, float x, float y, float e, float vX);
	~Meteoro();

	void inicializar(float vX);
	void atualizar();
	void desenhar();

	Cores getCor() { return cor; }
	float getX() { return x; }
	float getY() { return y; }
	float getVelocidadeX() { return velocidadeX; }
	float getVelocidadeY() { return velocidadeY; }
	Sprite getSprite() { return sprite; }

private:
	float x, y, velocidadeX, velocidadeY;
	Sprite sprite;
	Cores cor;
	int seed;
};

