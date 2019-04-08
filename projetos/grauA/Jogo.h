#pragma once
#include "libUnicornio.h"
#include "Nave.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();
private:
	void carregarAssets();
};

