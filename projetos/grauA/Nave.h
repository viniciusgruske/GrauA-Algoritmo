#pragma once
#include "libUnicornio.h"
#include "NaveAzul.h"
#include "NaveVerde.h"
#include "NaveVermelha.h"

class Nave
{
public:
	Nave();
	~Nave();

	void inicializar();
	void atualizar();
	void desenhar();

	virtual Sprite getSprite();

	float getX() { return x; }
	float getY() { return y; }
	float getVelocidade() { return velocidade; }

private:
	float x, y, velocidade;
	Nave *naves[3]{};
	int naveAtual;
};

