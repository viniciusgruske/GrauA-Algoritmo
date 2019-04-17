#include "NaveAzul.h"



NaveAzul::NaveAzul()
{
	inicializar();
}


NaveAzul::~NaveAzul()
{
}

void NaveAzul::setSpriteDefault()
{
	sprite.setSpriteSheet("naveAzul");
}

void NaveAzul::setSpriteEsquerda()
{
	sprite.setSpriteSheet("naveAzulEsquerda");
}

void NaveAzul::setSpriteDireita()
{
	sprite.setSpriteSheet("naveAzulDireita");
}

void NaveAzul::inicializar()
{
	sprite.setSpriteSheet("naveAzul");
}
