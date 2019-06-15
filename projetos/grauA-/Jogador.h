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
	void setVida(int i) { vidas += i; }

	float getX() { return x; }
	float getY() { return y; }
	float getVelocidade() { return velocidade; }
	int getVida() { return vidas; }
	Cores getCor() { return naveAtual; }
	Sprite getSprite();

	Nave *getNave(int j) { return naves[j]; }

private:
	Nave *naves[3]{};
	Cores naveAtual;

	int cdTiro;
	int hp, vidas;
	bool vivo;

	float x, y, velocidade, inerciaX, inerciaY;
};

