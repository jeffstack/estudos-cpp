#include <iostream>
#include <locale.h>
#include <string>
#include <iomanip>

using namespace std;

class Funcionario
{
	private:
		int prontuario;
		string nome;
		double salario;
		
    public:
    	Funcionario (int prontuario, string nome, double salario)
     	{
		 	this->prontuario = prontuario;
		 	this->nome = nome;
		 	this->salario = salario;
        }
        Funcionario ()
		{			
		} 
        
        void setProntuario(int prontuario)
        {
			this->prontuario = prontuario;
		}
		void setNome(string nome)
		{
			this->nome = nome;
		}
		void setSalario(double salario)
		{
			this->salario = salario;
		}
		int getProntuario()
		{
			return this->prontuario;
		}
		string getNome()
		{
			return this->nome;
		}
		double getSalario()
		{
			return this->salario;
		}
};

struct Lista
{
    Funcionario funcionario;
	Lista *prox;	
};

Lista* init()
{
	return NULL;
}

int isEmpty(Lista* lista)
{
	return (lista == NULL);
}

Lista* find(Lista* lista, int prontuario)
{
	Lista* aux;
	aux = lista;
    while(aux != NULL && aux->funcionario.getProntuario() != prontuario)
	{
		aux = aux->prox;
	}	
	return aux;
}

Lista* insert(Lista* lista, Funcionario f)
{
	Lista* novo = new Lista();
	novo->funcionario = f;
	novo->prox = lista;
	return novo;
}

Lista* remove(Lista* lista, int prontuario)
{
	Lista* ant = NULL;
    Lista* aux;
	aux = lista;
    while(aux != NULL && aux->funcionario.getProntuario() != prontuario)
	{
		ant = aux;
		aux = aux->prox;
	}	
	if (aux == NULL)
	{
		return lista;
	}	
	if (ant == NULL)
	{
		lista = aux->prox;
	}
	else
	{
		ant->prox = aux->prox;
	}
	delete aux;
	return lista;
}

void print(Lista* lista)
{
	Lista* aux;
	aux = lista;
	double totalSalarios = 0;
	cout << "----------- Listagem de Funcionários -----------" << endl;
	while(aux != NULL)
	{
		cout << "Prontuário: " << aux->funcionario.getProntuario() << " | "
		     << "Nome: " << aux->funcionario.getNome() << " | "
		     << "Salário: R$ " << fixed << setprecision(2) << aux->funcionario.getSalario() << endl;
		totalSalarios += aux->funcionario.getSalario();
		aux = aux->prox;
	}
	cout << "------------------------------------------------" << endl;
	cout << "Total dos Salários: R$ " << fixed << setprecision(2) << totalSalarios << endl;
	cout << "------------------------------------------------" << endl;
}

void freeLista(Lista* lista)
{
    Lista* aux;
	aux = lista;
	while(aux != NULL)
	{
		Lista* ant = aux->prox;
		delete aux;
		aux = ant;
	}	
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
	Lista *listaFuncionarios = init();
	int opcao;
	
	do
	{
		cout << endl;
		cout << "Menu:" << endl;
		cout << "0. Sair" << endl;
		cout << "1. Incluir" << endl;
		cout << "2. Excluir" << endl;
		cout << "3. Pesquisar" << endl;
		cout << "4. Listar" << endl;
		cout << "Escolha uma opção: ";
		cin >> opcao;
		
		if (opcao == 1)
		{
			int pront;
			string nome;
			double sal;
			
			cout << "Digite o prontuário: ";
			cin >> pront;
			
			if (find(listaFuncionarios, pront) != NULL)
			{
				cout << "Erro: Já existe um funcionário com este prontuário!" << endl;
			}
			else
			{
				cout << "Digite o nome: ";
				cin.ignore();
				getline(cin, nome);
				cout << "Digite o salário: ";
				cin >> sal;
				
				Funcionario f(pront, nome, sal);
				listaFuncionarios = insert(listaFuncionarios, f);
				cout << "Funcionário incluído com sucesso!" << endl;
			}
		}
		else if (opcao == 2)
		{
			int pront;
			cout << "Digite o prontuário para excluir: ";
			cin >> pront;
			
			if (find(listaFuncionarios, pront) == NULL)
			{
				cout << "Funcionário não encontrado!" << endl;
			}
			else
			{
				listaFuncionarios = remove(listaFuncionarios, pront);
				cout << "Funcionário excluído com sucesso!" << endl;
			}
		}
		else if (opcao == 3)
		{
			int pront;
			cout << "Digite o prontuário para pesquisar: ";
			cin >> pront;
			
			Lista* encontrado = find(listaFuncionarios, pront);
			if (encontrado != NULL)
			{
				cout << "Funcionário Encontrado:" << endl;
				cout << "Nome: " << encontrado->funcionario.getNome() << endl;
				cout << "Salário: R$ " << fixed << setprecision(2) << encontrado->funcionario.getSalario() << endl;
			}
			else
			{
				cout << "Funcionário não encontrado!" << endl;
			}
		}
		else if (opcao == 4)
		{
			if (isEmpty(listaFuncionarios))
			{
				cout << "A lista está vazia!" << endl;
			}
			else
			{
				print(listaFuncionarios);
			}
		}
		
	} while(opcao != 0);
	
	freeLista(listaFuncionarios);
	
	return 0;
}