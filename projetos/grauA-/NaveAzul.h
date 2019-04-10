#pragma once
#include "Nave.h"
class NaveAzul : public Nave
{
public:
	NaveAzul();
	~NaveAzul();

	Sprite getSprite() override { return sprite; }

private:
	void inicializar();
};

