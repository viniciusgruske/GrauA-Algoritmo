#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void main()
{
	bool logado = 0; //usado para saber se esta logado
	string inputLogin; //le o input do usuario para login para logar ou registrar
	string inputSenha; //le o input do usuario para senha para logar ou registrar
	string leitor1; //auxiliar para ler o arquivo de login
	string leitor2; // ""
	ifstream login; //le o arquivo de login
	ofstream registrar; //escreve no arquivo de login
	

	login.open("login.txt", ios::app); //abre o aquivo na ultima linha escrita
	registrar.open("login.txt", ios::app); // ""
	if (login.is_open()) //testa se o arquivo esta aberto
	{
		cout << "logar ou registrar?" << endl;
		cin >> leitor1;  //le input do usuario
		if (leitor1 == "logar") // testa o input para logar ou registrar
			{
			cout << "digite seu login" << endl; 
			cin >> inputLogin; //le o input de login do usuario
			cout << "digite sua senha" << endl;
			cin >> inputSenha; //le o input de senha do usuario
			while (!login.eof()) //enquanto o arquivo nao chegar ate a ultima linha escrita ele vai rodar infinitamente
			{
				getline(login, leitor1); //le a linha atual do arquivo "login", escreve no "leitor1" e pula para a linha debaixo
				if (leitor1 == inputLogin) //testa o input da linha para ver se achou um nome de login igual ao do input do usuario
				{
					getline(login, leitor2); //le a linha atual do arquivo "login", escreve no "leitor2" e pula para a linha debaixo
					if (leitor2 == inputSenha) //testa o input da linha para ver se achou um nome de senha igual ao do input do usuario
					{
						logado = 1;  //se o login e senha coincidem, avisa que um usuario foi logado
					}
				}
			}
			if (logado == 1) //avisa que um usuario foi encontrado
			{
				cout << "bem vindo " << inputLogin << endl;
			}
			else //avisa que um usuario com o login e senha digitados nao foi encontrado
			{
				cout << "login ou senha incorretos" << endl;
			}
		}
		if (leitor1 == "registrar") // testa o input para logar ou registrar
		{
			cout << "digite um novo login" << endl;
			cin >> inputLogin;
			registrar << endl << inputLogin; //no arquivo aberto:pula uma linha e escreve o input
			cout << "digite uma nova senha" << endl;
			cin >> inputSenha; 
			registrar << endl << inputSenha; //no arquivo aberto:pula uma linha e escreve o input
		}

	}
	else cout << "deu bosta" << endl; //avisa que o arquivo nao foi aberto porque um arquivo de texto com o nome fornecido nao foi encontrado na pasta principal

	system ("pause");
}