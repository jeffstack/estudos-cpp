#include <iostream>
using namespace std;

#define MAX 10

struct Fila {
    int ini;
    int fim;
    int nos[MAX];
};

Fila* init() {
    Fila *f = new Fila;
    f->ini = 0;
    f->fim = 0;
    return f;
}

int isEmpty(Fila *f) {
    return (f->ini == f->fim);
}

int incrementa(int i) {
    return (i == MAX ? 0 : ++i);
}

int count(Fila *f) {
    int k = 0;
    int i = f->ini;

    while (i != f->fim) 
	{
        k++;
        i = incrementa(i);
    }
    
    return k;
}

int enqueue(Fila *f, int v) {
    int podeEnfileirar = (incrementa(f->fim) != f->ini);

    if (podeEnfileirar) 
	{
        f->nos[f->fim] = v;
        f->fim = incrementa(f->fim);
    }
    
    return podeEnfileirar;
}

int dequeue(Fila *f) {
    int ret;
    
	if (isEmpty(f)) 
	{
        ret = -1;
    }
    else 
	{
        ret = f->nos[f->ini];
        f->ini = incrementa(f->ini);
    }
    
    return ret; 
}

int main() {
    Fila *senhasGeradas = init();
    Fila *senhasAtendidas = init();
    int opcao = -1;
    int senhaAtual = 1;

    while (true) 
	{
        cout << "\n--- SISTEMA DE ATENDIMENTO (VETOR) ---" << endl;
        cout << "Senhas aguardando: " << count(senhasGeradas) << endl;
        cout << "0. Sair" << endl;
        cout << "1. Gerar senha" << endl;
        cout << "2. Realizar atendimento" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 0) 
		{
            if (isEmpty(senhasGeradas)) 
			{
                cout << "\nEncerrando sistema..." << endl;
                cout << "Total de senhas atendidas: " << count(senhasAtendidas) << endl;
                break;
            } 
			else 
			{
                cout << "\nNão é possivel sair! Ainda há senhas aguardando atendimento." << endl;
            }
        } 
        else if (opcao == 1) 
		{
            if (enqueue(senhasGeradas, senhaAtual)) 
			{
                cout << "\nSenha " << senhaAtual << " gerada com sucesso!" << endl;
                senhaAtual++;
            } 
			else 
			{
                cout << "\nFila cheia! Não foi possivel gerar mais senhas." << endl;
            }
        } 
        else if (opcao == 2) 
		{
            if (isEmpty(senhasGeradas)) 
			{
                cout << "\nNão há senhas para atender!" << endl;
            } 
			else 
			{
                int senhaSendoAtendida = dequeue(senhasGeradas);
                cout << "\nAtendendo a senha: " << senhaSendoAtendida << endl;
                enqueue(senhasAtendidas, senhaSendoAtendida);
            }
        } 
        else 
		{
            cout << "\nOpcao invalida!" << endl;
        }
    }

    return 0;
}