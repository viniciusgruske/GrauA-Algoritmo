#include "Jogador.h"

Jogador::Jogador()
{
	inicializar();
}


Jogador::~Jogador()
{
}

void Jogador::inicializar()
{
	naves[0] = (Nave *) new NaveVermelha();
	naves[1] = (Nave *) new NaveVerde();
	naves[2] = (Nave *) new NaveAzul();

	x = gJanela.getLargura() / 4;
	y = gJanela.getAltura() / 2;
	cdTiro = 0;
	inerciaX = 0;
	inerciaY = 0;
	naveAtual = Vermelha;
	velocidade = 3;
}

void Jogador::atualizar()
{
	if (gTeclado.segurando[TECLA_CIMA] && y > (naves[naveAtual]->getSprite().getAltura() / 2))
	{
		y -= velocidade;
		naves[naveAtual]->setSpriteCima();
	}
	if (gTeclado.segurando[TECLA_ESQ] && x > (naves[naveAtual]->getSprite().getLargura() / 2))
	{
		x -= velocidade;
	}
	if (gTeclado.segurando[TECLA_BAIXO] && y < (gJanela.getAltura() - (naves[naveAtual]->getSprite().getAltura() / 2)))
	{
		y += velocidade;
		naves[naveAtual]->setSpriteBaixo();
	}
	if (gTeclado.segurando[TECLA_DIR] && x < (gJanela.getLargura() - (naves[naveAtual]->getSprite().getLargura() / 2)))
	{
		x += velocidade;
	}
	if (gTeclado.segurando[TECLA_CIMA] && gTeclado.segurando[TECLA_BAIXO])
	{
		naves[naveAtual]->setSpriteDefault();
	}
	if (gTeclado.soltou[TECLA_CIMA])
	{
		naves[naveAtual]->setSpriteDefault();
		inerciaY = -velocidade;
	}
	if (gTeclado.soltou[TECLA_ESQ])
	{
		inerciaX = -velocidade;
	}
	if (gTeclado.soltou[TECLA_BAIXO])
	{
		naves[naveAtual]->setSpriteDefault();
		inerciaY = velocidade;
	}
	if (gTeclado.soltou[TECLA_DIR])
	{
		inerciaX = velocidade;
	}
	if (gTeclado.pressionou[TECLA_Q])
	{
		naveAtual = Vermelha;
	}
	if (gTeclado.pressionou[TECLA_W])
	{
		naveAtual = Verde;
	}
	if (gTeclado.pressionou[TECLA_E])
	{
		naveAtual = Azul;
	}
	if (gTeclado.segurando[TECLA_ESPACO])
	{
		if ((cdTiro % 20) == 0)
		{
			naves[naveAtual]->atirar(x, y, naveAtual);
			cdTiro = 0;
		}
	}

	if (inerciaX != 0)
	{
		x += inerciaX;
		inerciaX -= inerciaX * 0.025;
	}
	/*if (inerciaY != 0)
	{
		x += inerciaY;
		inerciaY -= inerciaY * 0.025;
	}*/

	// Cooldown Tiro
	if (cdTiro < 20)
	{
		cdTiro++;
	}
	else
	{
		cdTiro = 20;
	}

	// Atualizar Tiro da Nave
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 15; i++)
		{
			if (naves[j]->getTiro(i) != nullptr)
			{
				naves[j]->getTiro(i)->atualizar();
			}
		}
	}
}

void Jogador::desenhar()
{
	naves[naveAtual]->desenhar(x, y);

	// Desenhar Tiro da Nave
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 15; i++)
		{
			if (naves[j]->getTiro(i) != nullptr)
			{
				naves[j]->getTiro(i)->desenhar();
			}
		}
	}
}

Sprite Jogador::getSprite()
{
	int i;
	if (naveAtual == Vermelha)
	{
		i = 0;
	}
	else if (naveAtual == Verde)
	{
		i = 1;
	}
	else
	{
		i = 2;
	}
	return naves[i]->getSprite();;
}
