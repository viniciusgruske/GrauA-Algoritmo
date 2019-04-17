#pragma once
#include "Nave.h"
class NaveAzul : public Nave
{
public:
	NaveAzul();
	~NaveAzul();

	Sprite getSprite() override { return sprite; }

	void setSpriteDefault() override;
	void setSpriteEsquerda() override;
	void setSpriteDireita() override;

private:
	void inicializar();
};

