#pragma once
#include "Nave.h"
class NaveVerde : public Nave
{
public:
	NaveVerde();
	~NaveVerde();

	Sprite getSprite() override { return sprite; }

private:
	void inicializar();
};

