#pragma once
#include "Nave.h"
class NaveVermelha : public Nave
{
public:
	NaveVermelha();
	~NaveVermelha();

	void inicializar();

	Sprite getSprite() override { return sprite; }

private:
	Sprite sprite;
};

