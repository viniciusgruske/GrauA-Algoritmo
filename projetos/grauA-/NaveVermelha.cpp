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

void NaveVermelha::setSpriteEsquerda()
{
	sprite.setSpriteSheet("naveVermelhaEsquerda");
}

void NaveVermelha::setSpriteDireita()
{
	sprite.setSpriteSheet("naveVermelhaDireita");
}

void NaveVermelha::inicializar()
{
	sprite.setSpriteSheet("naveVermelha");
}