#pragma once
#include "Nave.h"
class NaveVermelha : public Nave
{
public:
	NaveVermelha();
	~NaveVermelha();

	Sprite getSprite() override { return sprite; }

private:
	void inicializar();
};

