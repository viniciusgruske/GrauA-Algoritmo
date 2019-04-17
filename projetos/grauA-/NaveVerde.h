#pragma once
#include "Nave.h"
class NaveVerde : public Nave
{
public:
	NaveVerde();
	~NaveVerde();

	Sprite getSprite() override { return sprite; }

	void setSpriteDefault() override;
	void setSpriteEsquerda() override;
	void setSpriteDireita() override;

private:
	void inicializar();
};

