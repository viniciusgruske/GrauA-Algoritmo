#pragma once
#include "NaveAzul.h"
#include "NaveVerde.h"
#include "NaveVermelha.h"

class Jogador
{
public:
	Jogador();
	~Jogador();

	void inicializar();
	void atualizar();
	void desenhar();

	void setX(float i) { x = i; }
	void setY(float i) { y = i; }
	void setVelocidade(float i) { velocidade = i; }

	float getX() { return x; }
	float getY() { return y; }
	float getVelocidade() { return velocidade; }

private:
	Nave *naves[3]{};
	Cores naveAtual;

	int cdTiro;

	float x, y, velocidade;
};

