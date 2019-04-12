#pragma once
#include "libUnicornio.h"

enum Cores {Vermelha, Verde, Azul};

class Tiro
{
public:
	Tiro(float x, float y, Cores c);
	~Tiro();

	void atualizar();
	void desenhar();

private:
	float x, y, velocidade;
	Cores cor;
	Sprite sprite;
};

