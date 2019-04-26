#pragma once
#include "Nave.h"
class NaveAzul : public Nave
{
public:
	NaveAzul();
	~NaveAzul();

	//Sprite getSprite() override { return sprite; }

	void setSpriteDefault() override;
	void setSpriteCima() override;
	void setSpriteBaixo() override;

private:
	void inicializar();
};

