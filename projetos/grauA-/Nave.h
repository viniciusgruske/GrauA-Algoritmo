#pragma once
#include "libUnicornio.h"
#include "Tiro.h"

class Nave
{
public:
	Nave();
	~Nave();

	void inicializar();
	void desenhar(float x, float y);

	virtual Sprite getSprite();
	void atirar(float x, float y, Cores c);

	Tiro* getTiro(int i) { return this->tiro[i]; }

protected:
	int indexTiro;
	Sprite sprite;
	Tiro *tiro[20];
};

