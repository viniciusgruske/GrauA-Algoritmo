#include "Meteoro.h"



Meteoro::Meteoro()
{
	inicializar();
}


Meteoro::~Meteoro()
{
}

void Meteoro::inicializar()
{	
	seed = rand() % 3;

	if (seed == 0)
	{
		cor = Vermelha;
		sprite.setSpriteSheet("meteoroVermelho");
	}
	else if (seed == 1)
	{
		cor = Verde;
		sprite.setSpriteSheet("meteoroVerde");
	}
	else
	{
		cor = Azul;
		sprite.setSpriteSheet("meteoroAzul");
	}

	seed = rand() % 3;

	if (seed == 0)
	{
		sprite.setEscala(1, 1);
	}
	else if (seed == 1)
	{
		sprite.setEscala(0.5, 0.5);
	}
	else
	{
		sprite.setEscala(0.25, 0.25);
	}

	x = gJanela.getLargura() + sprite.getLargura();
	y = rand() % gJanela.getAltura();
	velocidade = 1;
}

void Meteoro::atualizar()
{
	x -= velocidade;
}

void Meteoro::desenhar()
{
	sprite.desenhar(x, y);
}

