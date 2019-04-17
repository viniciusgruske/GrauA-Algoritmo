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

void NaveVerde::setSpriteEsquerda()
{
	sprite.setSpriteSheet("naveVerdeEsquerda");
}

void NaveVerde::setSpriteDireita()
{
	sprite.setSpriteSheet("naveVerdeDireita");
}

void NaveVerde::inicializar()
{
	sprite.setSpriteSheet("naveVerde");
}
