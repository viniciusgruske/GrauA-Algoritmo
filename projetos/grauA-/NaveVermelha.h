#pragma once
#include "Nave.h"
class NaveVermelha : public Nave
{
public:
	NaveVermelha();
	~NaveVermelha();

	//Sprite getSprite() override { return sprite; }

	void setSpriteDefault() override;
	void setSpriteCima() override;
	void setSpriteBaixo() override;

private:
	void inicializar();
};

