#include <iostream>
using namespace std;

struct No {
    int dado;
    No *prox;
};

struct Fila {
    No *ini;
    No *fim;
};

Fila* init() {
    Fila *f = new Fila;
    f->ini = NULL;
    f->fim = NULL;
    
	return f;
}

int isEmpty(Fila *f) {
    return (f->ini == NULL);
}

int count(Fila *f) {
    int k = 0;
    No *no = f->ini;
    
	while (no != NULL) 
	{
        k++;
        no = no->prox;
    }
    return k;
}

void enqueue(Fila *f, int v) {
    No *no = new No;
    no->dado = v;
    no->prox = NULL;
    
	if(isEmpty(f)) 
	{
        f->ini = no;
    } 
	else 
	{
        f->fim->prox = no;
    }
    
    f->fim = no;
}

int dequeue(Fila *f) {
    int ret;
    if (isEmpty(f)) 
	{
        ret = -1;
    } 
	else 
	{
        No *no = f->ini;
        ret = no->dado;
        f->ini = no->prox;
        
		if (f->ini == NULL) 
		{
            f->fim = NULL;
        }
        
        delete no;
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
        cout << "\n--- SISTEMA DE ATENDIMENTO (PONTEIRO) ---" << endl;
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
                cout << "\nNao e possivel sair! Ainda ha senhas aguardando atendimento." << endl;
            }
        } 
        else if (opcao == 1) 
		{
            enqueue(senhasGeradas, senhaAtual);
            cout << "\nSenha " << senhaAtual << " gerada com sucesso!" << endl;
            senhaAtual++;
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