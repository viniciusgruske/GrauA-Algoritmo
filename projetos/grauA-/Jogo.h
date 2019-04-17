#pragma once
#include "libUnicornio.h"
#include "Jogador.h"
#include "Meteoro.h"
#include <time.h>

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

	Jogador *jogador;
	Meteoro *meteoros[100];
};
