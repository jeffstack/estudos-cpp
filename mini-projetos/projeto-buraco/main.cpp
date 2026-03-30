#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int** baralho;
#define B 2 // Baralho
#define C 52 // Cartas
int** mao;
#define P 4 // Player
#define M 11 // Mão

int i = 0;
int j = 0;

int main(int argc, char** argv)
{
	// Cria matriz 2D para representar 2 baralhos
	baralho = new int*[B];
	for(i = 0; i < B; i++)
	{
		baralho[i] = new int[C];
	}
	
	// Popula o baralho com naipe, valor da carta e identificação do baralho
	for(i = 0; i < B; i++)
	{
		for(j = 0; j < C; j++)
		{
			if(j <= 12)
			{
		    	   baralho[i][j] = 1000;
		    	   baralho[i][j] += (j+1)*10;
			} else if(j <= 25)
			{
				baralho[i][j] = 2000;
				baralho[i][j] +=((j+1)-13)*10;
			} else if(j <= 38)
			{
				baralho[i][j] = 3000;
				baralho[i][j] += ((j+1)-26)*10;
			}
			else
			{
				baralho[i][j] = 4000;
				baralho[i][j] += ((j+1)-39)*10;
			}
			
			if(i == 0)
			{
				baralho[i][j] += 1;	
			}
			else
			{
				baralho[i][j] += 2;
			}
		}
	}
	
	srand(time(NULL));
	
	// Cria matriz 2D para representar 4 jogadores
	mao = new int*[P];
	for(i = 0; i < P; i++)
	{
		mao[i] = new int[M];
	}
	
	// Sorteia cartas aleatórias para população e evita repetição marcando as usadas com -1
	for(i = 0; i < P; i++)
	{
		for(j = 0; j < M; j++)
		{
			int aux1;
			int aux2;
			
			do
			{
				aux1 = rand() % B;
				aux2 = rand() % C;

			} while(baralho[aux1][aux2] == -1);
		
			mao[i][j] = baralho[aux1][aux2];
			baralho[aux1][aux2] = -1;
		}
	}
	
	// Exibe as 11 cartas de cada jogador
	for(i = 0; i < P; i++)
	{
		cout << "==============" << endl;
		
		cout << "Jogador " << i+1 << ":" << endl;
		
		for(j = 0; j< M; j++)
		{ 
			cout << mao[i][j] << endl;
		}
		
		cout << "==============" << endl;
	}
	
	// Libera a memória alocada dinamicamente para o baralho
	for(i = 0; i < B; i++)
	{
    	delete[] baralho[i];
	}
	delete[] baralho;
	
	// // Libera a memória alocada dinamicamente para a mão
	for(i = 0; i < P; i++)
	{
  	  delete[] mao[i];
	}
	delete[] mao;
	
	
	return 0;
}