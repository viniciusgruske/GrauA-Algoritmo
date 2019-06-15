#pragma once
#include "libUnicornio.h"
#include "Jogador.h"
#include "Meteoro.h"
#include <time.h>

enum Telas {telaMenu, telaJogo, telaGameOver, telaPause, sair};

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
	void criarMeteoroColisao(int i, Cores c, float x, float y, float e, float vX);
	void colisaoMeteoroTiro();
	void colisaoMeteoroNave();
	void controlarDificuldade();

	void resetar();

	void executarTelaMenu();
	void executarTelaJogo();
	void executarTelaGameOver();
	void executarTelaPause();

	void background();

	Telas tela;
	Jogador *jogador;
	Meteoro *meteoros[100];
	//vector <Meteoro> *meteoros;
	Sprite bg1, bg2, bgParalax1, bgParalax2, pause, vidas;
	BotaoSprite botaoJogar, botaoVoltar, botaoSair;
	Texto level;
	int indexMeteoro, cdMeteoro, dificuldade, cdDificuldade;;

	float bgX, bgParalaxX;
	bool bgParalax;
};

