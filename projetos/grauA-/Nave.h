#pragma once
#include "libUnicornio.h"

class Nave
{
public:
	Nave();
	~Nave();

	void inicializar();
	void atualizar();
	void desenhar(float x, float y);

	void atirar();

	virtual Sprite getSprite();

protected:
	Sprite sprite;
};

