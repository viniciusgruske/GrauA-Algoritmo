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

	seed = rand() % 4;
	sprite.setEscala(0.25 + 0.25 * seed, 0.25 + 0.25 * seed);

/*	if (seed == 0)
	{
		sprite.setEscala(1, 1);
	}
	else if (seed == 1)
	{
		sprite.setEscala(0.75, 0.75);
	}
	else if (seed == 3)
	{
		sprite.setEscala(0.5, 0.5);
	}
	else
	{
		sprite.setEscala(0.25, 0.25);
	}*/

	//seed = rand() % 5;
	//velocidade = 0.3 + 0.3 * seed;

	velocidadeX = 1;

	seed = rand() % 5;
	if (seed == 0)
	{
		velocidadeY = 0;
	} 
	else if (seed == 1 || seed == 2)
	{
		seed = rand() % 8;
		velocidadeY = 0.05 + seed * 0.05;
	}
	else
	{
		seed = rand() % 8;
		velocidadeY = -(0.05 +seed * 0.05);
	}
	x = gJanela.getLargura() + sprite.getLargura();
	y = rand() % gJanela.getAltura();
}

void Meteoro::atualizar()
{
	x -= velocidadeX;
	y += velocidadeY;
}

void Meteoro::desenhar()
{
	sprite.desenhar(x, y);
}

