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

void NaveAzul::setSpriteCima()
{
	sprite.setSpriteSheet("naveAzulCima");
}

void NaveAzul::setSpriteBaixo()
{
	sprite.setSpriteSheet("naveAzulBaixo");
}

void NaveAzul::inicializar()
{
	sprite.setSpriteSheet("naveAzul");
}
