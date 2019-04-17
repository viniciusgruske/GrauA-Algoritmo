#pragma once
#include "Nave.h"
class NaveVermelha : public Nave
{
public:
	NaveVermelha();
	~NaveVermelha();

	Sprite getSprite() override { return sprite; }

	void setSpriteDefault() override;
	void setSpriteEsquerda() override;
	void setSpriteDireita() override;

private:
	void inicializar();
};

