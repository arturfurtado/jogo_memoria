// Memoria.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	char baralho1[4][4] = { '5','7','1','6',//cria o primeiro baralho
							'2','4','3','5',
							'1','8','6','4',
							'7'	,'8','2','3' },
	baralho2[4][4]={'2', '4', '6', '5',//cria o segundo baralho
					'8', '6', '2', '7',
					'7', '3', '3', '1',
					'5', '4', '8', '1'},
	baralho3[4][4]={'4', '3', '8', '5',//cria o terceiro baralho
					'6', '4', '8', '7',
					'2', '3', '1', '5',
					'6', '7', '2', '1'},
	baralho[4][4];//cria o baralho que sera usado no jogo
	int jogadas=0,aux1=5,aux2=5,aux3=6,aux4=6, pontos=0,menu=0;//variavel aux vai ler
	char baralhoaux[4][4];


	do {
		menu = rand() % 3;//sorteia qual baralho sera usado
		jogadas = 0;
		if (menu == 0) {
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					baralho[i][j] = baralho1[i][j];//adiciona o baralho1 no baralho que vai ser usado no jogo
					baralhoaux[i][j] = '*';//adiciona * no baralho auxiliar
				}
			}
		}
		else if (menu == 1) {
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					baralho[i][j] = baralho2[i][j];//adiciona o baralho2 no baralho que vai ser usado no jogo
					baralhoaux[i][j] = '*';//adiciona * no baralho auxiliar
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					baralho[i][j] = baralho3[i][j];//adiciona o baralho3 no baralho que vai ser usado no jogo
					baralhoaux[i][j] = '*';//adiciona * no baralho auxiliar
				}
			}
		}
		cout << "1-jogar\n";
		cout << "2-criador\n";
		cout << "3-sair\n";
		cin >> menu;
		system("CLS");

		if (menu == 1){

			do//começa o jogo
			{

				cout << "jogada: " << jogadas << "\n";//printa o numero da jogada

				for (int i = 0; i < 4; i++)
				{
					cout <<' ' << i << ' ';//desenha a guia
				}
				cout << "\n";

				for (int i = 0; i < 4; i++)
				{
					cout << i;//desenha a culuna
					for (int j = 0; j < 4; j++)
					{
						cout << "[" << baralhoaux[i][j] << "]";//printa o baralho auxiliar
					}
					cout << "\n";
				}
				do
				{
					cin >> aux1;//le a primeira jogada
					cin >> aux2;

				} while (aux1 > 3 || aux2 > 3 || aux1 < 0 || aux2 < 0 || baralhoaux[aux1][aux2]!='*');//so vai aceitar se o valor das variaveis for maior 0 e menor que 4

				system("CLS");//limpa a tela depois da leitura  para poder desenhar a matriz já com o novo nuemro
				cout << "jogada: " << jogadas << "\n";

				for (int i = 0; i < 4; i++)
				{
					cout << ' ' << i << ' ';//desenha a guia
				}
				cout << "\n";

				for (int i = 0; i < 4; i++)
				{
					cout << i;//desenha a culuna
					for (int j = 0; j < 4; j++)
					{
						if (i == aux1 && j == aux2)//printa aonde esta a primeira jogada
						{
							cout << "[" << baralho[i][j] << "]";
						}
						else {
							cout << "[" << baralhoaux[i][j] << "]";
						}
					}
					cout << "\n";//pula a linha
				}
				do
				{
					cin >> aux3;//le a segunda posição
					cin >> aux4;
				} while (aux3 > 3 || aux4 > 3 || aux3 < 0 || aux4 < 0 || aux1==aux3 && aux2==aux4 || baralhoaux[aux3][aux4] != '*');//so vai aceitar se o valor das variaveis for maior 0 e menor que 4

				system("CLS");
				cout << "jogada: " << jogadas << "\n";

				for (int i = 0; i < 4; i++)
				{
					cout << ' ' << i << ' ';//desenha a guia
				}
				cout << "\n";


				for (int i = 0; i < 4; i++)
				{
					cout << i;//desenha a culuna
					for (int j = 0; j < 4; j++)
					{
						if (i == aux3 && j == aux4)
						{
							cout << "[" << baralho[i][j] << "]";//desenha o numero na posição do aux3 e aux4
						}
						else if (i == aux1 && j == aux2)
						{
							cout << "[" << baralho[i][j] << "]";//desenha o numero na posição do aux1 e aux2
						}
						else
						{
							cout << "[" << baralhoaux[i][j] << "]";//desenha o aux
						}
					}
					cout << "\n";
				}
				if (baralho[aux1][aux2] == baralho[aux3][aux4])//se as cartas das posições forem iguais ele entra
				{
					cout << "JOGADA OK";
					pontos++;
					baralhoaux[aux1][aux2] = baralho[aux1][aux2];//seta o valor do baralho no baralho aux quando você acerta
					baralhoaux[aux3][aux4] = baralho[aux3][aux4];//seta o valor do baralho no baralho aux quando você acerta
					if (pontos == 8) {
						jogadas = 25;//se a pontuação chegar em 8 o jogo termina
					}
				}
				else {
					cout << "JOGADA NOK";
				}
				cout << "\n";
				system("PAUSE");//pausa pra proxima jogada
				system("CLS");
				jogadas++;//aumenta o numero de jogada
			} while (jogadas <= 24);//jogo acontece enquanto a variavel jogadas  for  menor ou igual a 24
				if (pontos == 8)
				{
					cout << "VOCE VENCEU";
				}
				else {
					cout << "VOCE PERDEU";
				}
				cout << "\n";
				system("PAUSE");
		}
		else if (menu == 2)
		{
			cout << "Artur Ramiro Furtado e Delael Do Nascimento\n";
			system("PAUSE");
		}
		else {
			return 0;
		}
		system("CLS");
	} while (1);
}
