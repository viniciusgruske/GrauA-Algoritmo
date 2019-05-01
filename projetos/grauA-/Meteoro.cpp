#include "Meteoro.h"



Meteoro::Meteoro()
{
	inicializar();
}

Meteoro::Meteoro(Cores c, float x, float y, float e, float vX)
{
	switch (c)
	{
	case Vermelha:
		cor = Vermelha;
		sprite.setSpriteSheet("meteoroVermelho");
		break;
	case Verde:
		cor = Verde;
		sprite.setSpriteSheet("meteoroVerde");
		break;
	case Azul:
		cor = Azul;
		sprite.setSpriteSheet("meteoroAzul");
		break;
	}

	seed = rand() % sprite.getLargura() / 2;
	this->x = (x - (sprite.getLargura() / 4)) + seed;
	
	seed = rand() % sprite.getAltura() / 2;
	this->y = (y - (sprite.getAltura() / 4)) + seed;

	sprite.setEscala(e, e);

	velocidadeX = vX ;

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
		velocidadeY = -(0.05 + seed * 0.05);
	}
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

