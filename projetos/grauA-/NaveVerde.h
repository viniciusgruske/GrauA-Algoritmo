#pragma once
#include "Nave.h"
class NaveVerde : public Nave
{
public:
	NaveVerde();
	~NaveVerde();

	//Sprite getSprite() override { return sprite; }

	void setSpriteDefault() override;
	void setSpriteCima() override;
	void setSpriteBaixo() override;

private:
	void inicializar();
};

