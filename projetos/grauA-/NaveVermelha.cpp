#include "NaveVermelha.h"



NaveVermelha::NaveVermelha()
{
	inicializar();
}


NaveVermelha::~NaveVermelha()
{
}

void NaveVermelha::setSpriteDefault()
{
	sprite.setSpriteSheet("naveVermelha");
}

void NaveVermelha::setSpriteCima()
{
	sprite.setSpriteSheet("naveVermelhaCima");
}

void NaveVermelha::setSpriteBaixo()
{
	sprite.setSpriteSheet("naveVermelhaBaixo");
}

void NaveVermelha::inicializar()
{
	sprite.setSpriteSheet("naveVermelha");
}