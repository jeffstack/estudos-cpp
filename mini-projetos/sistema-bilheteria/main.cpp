#include <iostream>
#include <iomanip>
#include <locale.h>
#include <stdlib.h>

using namespace std;

#define FIL 15
#define POL 40
char **poltronas;
int qtdOcupado;
int valorBilheteria;

void mostrar_mapa()
{	
	for(int i = 0; i < FIL; ++i)
	{
		for(int j = 0; j < POL; ++j)
		{
			cout << "|" << poltronas[i][j];
		}
		
		cout << "|" << endl;
	}	
	
	cout << endl;
	system("pause");
}

void calcular_faturamento()
{
	qtdOcupado = 0;
	valorBilheteria = 0;
	
	for(int i=0; i < FIL; ++i)
	{
		for(int j = 0; j < POL; ++j)
		{
			if(poltronas[i][j] == '#')
			{
				qtdOcupado = qtdOcupado+1;
				
				if(i+1 <= 5)
				{
					valorBilheteria += 50;
				} else if(i+1 <= 10)
				{
					valorBilheteria += 30;
				}
				else
				{
					valorBilheteria += 15;
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
	int c;
	int i;
	int j;
	poltronas = new char*[FIL];
	for(int i=0; i < FIL; ++i)
	{
		poltronas[i] = new char[POL];
	}
	for(int i = 0; i < FIL; ++i)
	{
		for(int j = 0; j < POL; ++j)
		{
			poltronas[i][j] = '.';
		}
	}
	
	do
	{
		cout << "Opções:" << endl;
		cout << "0. Finalizar." << endl;
		cout << "1. Reservar poltrona." << endl;
		cout << "2. Mapa de ocupação." << endl;
		cout << "3. Faturamento." << endl;
		cout << "=======================" << endl;
		cout << "Escolha uma opção: ";
		cin >> c;
		
		if(c < 0 || c > 3)
		{
			cout << "O número digitado está fora do quadro de opções!" << endl;
			cout << endl;
			system("pause");
		} else if(c == 1)
		{
			cout << endl;
			cout << "Insira o número da fileira (1 a 15): ";
			cin >> i;
			
			if(i > 0 && i <= 15)
			{
				cout << "Agora insira o número da poltrona (1 a 40): ";
				cin >> j; 
				
				if(j > 0 && j <= 40)
				{
					if(poltronas[i-1][j-1] == '.')
					{
						poltronas[i-1][j-1] = '#';
						cout << "O lugar foi reservado com sucesso!" << endl;
						cout << endl;
						system("pause");
					}
					else
					{
						cout << "O lugar está ocupado." << endl;
						cout << endl;
						system("pause");
					}
				}
				else
				{
					cout << "Não existe uma poltrona com o número digitado. Tente novamente." << endl;
					cout << endl;
					system("pause");
				}
			}
			else
			{
				cout << "Não existe uma fileira com o número digitado. Tente novamente." << endl;
				cout << endl;
				system("pause");
			}
		} else if(c == 2)
		{
			cout << endl;
			cout << "Mapa de Ocupação:" << endl;
			mostrar_mapa(); 
		}else if(c == 3)
		{
			calcular_faturamento();
			
			cout << endl;
			cout << "Qtde de lugares ocupados: " << qtdOcupado << endl;
			cout << "Valor da bilheteria: R$" << valorBilheteria << endl;
			cout << endl;
			system("pause");
		}
		
		system("cls");
	} while(c > 0);
	
	for(int i = 0; i < FIL; ++i)
	{
    	delete[] poltronas[i];
	}
	delete[] poltronas;
	
	return 0;
}