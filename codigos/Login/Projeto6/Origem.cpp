#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void main()
{
	bool logado = 0;
	string inputLogin;
	string inputSenha;
	string leitor1;
	string leitor2;
	ifstream login;
	ofstream registrar;
	

	login.open("login.txt", ios::app);
	registrar.open("login.txt", ios::app);
	if (login.is_open())
	{
		cout << "logar ou registrar?" << endl;
		cin >> leitor1;
		if (leitor1 == "logar") 
			{
			cout << "digite seu login" << endl;
			cin >> inputLogin;
			cout << "digite sua senha" << endl;
			cin >> inputSenha;
			while (!login.eof())
			{
				getline(login, leitor1);
				if (leitor1 == inputLogin)
				{
					getline(login, leitor2);
					if (leitor2 == inputSenha)
					{
						logado = 1;
					}
				}
			}
			if (logado == 1)
			{
				cout << "bem vindo " << inputLogin << endl;
			}
			else
			{
				cout << "login ou senha incorretos" << endl;
			}
		}
		if (leitor1 == "registrar")
		{
			cout << "digite um novo login" << endl;
			cin >> inputLogin;
			registrar << endl << inputLogin;
			cout << "digite uma nova senha" << endl;
			cin >> inputSenha;
			registrar << endl <<inputSenha;
		}

	}
	else cout << "deu bosta" << endl;

	system ("pause");
}