#include "NaveVerde.h"



NaveVerde::NaveVerde()
{
	inicializar();
}


NaveVerde::~NaveVerde()
{
}

void NaveVerde::setSpriteDefault()
{
	sprite.setSpriteSheet("naveVerde");
}

void NaveVerde::setSpriteCima()
{
	sprite.setSpriteSheet("naveVerdeCima");
}

void NaveVerde::setSpriteBaixo()
{
	sprite.setSpriteSheet("naveVerdeBaixo");
}

void NaveVerde::inicializar()
{
	sprite.setSpriteSheet("naveVerde");
}
