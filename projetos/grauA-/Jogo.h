#pragma once
#include "libUnicornio.h"
#include "Jogador.h"
#include "Meteoro.h"
#include <time.h>

enum Telas {telaMenu, telaJogo, telaGameOver};

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
	void criarMeteoro();
	void colisaoMeteoroTiro();
	void colisaoMeteoroNave();

	void resetar();

	void executarTelaMenu();
	void executarTelaJogo();
	void executarTelaGameOver();

	void background();

	Telas tela;
	Jogador *jogador;
	Meteoro *meteoros[100];
	Sprite bg1, bg2, bgParalax1, bgParalax2;
	int indexMeteoro, cdMeteoro;

	float bgX, bgParalaxX;
};

