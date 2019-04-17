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
	x = 400;
	y = -100;
	velocidade = 1;

	seed = rand() % 4;
	
	if (seed == 0)
	{
		cor = Vermelha;
	}
	else if (seed == 1)
	{
		cor = Verde;
	}
	else
	{
		cor = Azul;
	}

	if (cor == Vermelha)
	{
		sprite.setSpriteSheet("meteoroVermelho");
	}
	else if (cor == Verde)
	{
		sprite.setSpriteSheet("meteoroVerde");
	}
	else if (cor == Azul)
	{
		sprite.setSpriteSheet("meteoroAzul");
	}
}

void Meteoro::atualizar()
{
	y += velocidade;
}

void Meteoro::desenhar()
{
	sprite.desenhar(x, y);
}

