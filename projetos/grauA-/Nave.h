#pragma once
#include "libUnicornio.h"
#include "Tiro.h"

class Nave
{
public:
	Nave();
	~Nave();

	void inicializar();
	void desenhar(float x, float y);

	virtual Sprite getSprite();

	virtual void setSpriteDefault();
	virtual void setSpriteEsquerda();
	virtual void setSpriteDireita();

	void atirar(float x, float y, Cores c);

	Tiro *getTiro(int i) { return this->tiro[i]; }

	void setTiroNull(int i) { tiro[i] = nullptr; }

protected:
	int indexTiro;
	Sprite sprite;
	Tiro *tiro[10];
};

