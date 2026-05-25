#include <iostream>
using namespace std;

//PILHA COM LISTA ENCADEADA

struct No {
    int valor;
    No* proximo;
};

struct PilhaLista {
    No* topo;

    PilhaLista() {
        topo = nullptr;
    }

    bool estaVazia() {
        return topo == nullptr;
    }

    void empilhar(int valor) {
        No* novo = new No();
        novo->valor = valor;
        novo->proximo = topo;
        topo = novo;
    }

    int desempilhar() {
        if (estaVazia()) {
            cout << "Pilha vazia!" << endl;
            return -1;
        }
        No* removido = topo;
        int valor = removido->valor;
        topo = topo->proximo;
        delete removido;
        return valor;
    }
};


//PILHA COM VETOR

const int TAMANHO_MAX = 30;

struct PilhaVetor {
    int dados[TAMANHO_MAX];
    int indiceTopo;

    PilhaVetor() {
        indiceTopo = -1;
    }

    bool estaVazia() {
        return indiceTopo == -1;
    }

    bool estaCheia() {
        return indiceTopo == TAMANHO_MAX - 1;
    }

    void empilhar(int valor) {
        if (estaCheia()) {
            cout << "Pilha cheia!" << endl;
            return;
        }
        indiceTopo++;
        dados[indiceTopo] = valor;
    }

    int desempilhar() {
        if (estaVazia()) {
            cout << "Pilha vazia!" << endl;
            return -1;
        }
        int valor = dados[indiceTopo];
        indiceTopo--;
        return valor;
    }
};


int main() {

    PilhaLista pilhaParesLista;
    PilhaLista pilhaImparesLista;

    PilhaVetor pilhaParesVetor;
    PilhaVetor pilhaImparesVetor;

    int numeroAtual;
    int numeroAnterior;
    bool primeiroNumero = true;

    cout << "Digite 30 numeros inteiros em ordem CRESCENTE." << endl;
    cout << "Cada numero deve ser MAIOR que o anterior." << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 1; i <= 30; i++) {

        while (true) {
            cout << "Numero [" << i << "/30]: ";
            cin >> numeroAtual;

            if (primeiroNumero) {
                primeiroNumero = false;
                break;
            }

            if (numeroAtual > numeroAnterior) {
                break;
            } else {
                cout << "  ERRO! O numero deve ser maior que " 
                     << numeroAnterior << ". Tente novamente." << endl;
            }
        }

        if (numeroAtual % 2 == 0) {
            pilhaParesLista.empilhar(numeroAtual);
            pilhaParesVetor.empilhar(numeroAtual);
            cout << "  -> Par: empilhado!" << endl;
        } else {
            pilhaImparesLista.empilhar(numeroAtual);
            pilhaImparesVetor.empilhar(numeroAtual);
            cout << "  -> Impar: empilhado!" << endl;
        }

        numeroAnterior = numeroAtual;
    }

    // --- Resultado: Lista Encadeada ---

    cout << endl << "Resultado com Lista Encadeada:" << endl;

    cout << endl << "Numeros impares (decrescente):" << endl;
    if (pilhaImparesLista.estaVazia()) {
        cout << "Nenhum numero impar foi digitado." << endl;
    } else {
        while (!pilhaImparesLista.estaVazia()) {
            cout << pilhaImparesLista.desempilhar() << " ";
        }
        cout << endl;
    }

    cout << endl << "Numeros pares (decrescente):" << endl;
    if (pilhaParesLista.estaVazia()) {
        cout << "Nenhum numero par foi digitado." << endl;
    } else {
        while (!pilhaParesLista.estaVazia()) {
            cout << pilhaParesLista.desempilhar() << " ";
        }
        cout << endl;
    }

    // --- Resultado: Vetor ---

    cout << endl << "Resultado com Vetor:" << endl;

    cout << endl << "Numeros impares (decrescente):" << endl;
    if (pilhaImparesVetor.estaVazia()) {
        cout << "Nenhum numero impar foi digitado." << endl;
    } else {
        while (!pilhaImparesVetor.estaVazia()) {
            cout << pilhaImparesVetor.desempilhar() << " ";
        }
        cout << endl;
    }

    cout << endl << "Numeros pares (decrescente):" << endl;
    if (pilhaParesVetor.estaVazia()) {
        cout << "Nenhum numero par foi digitado." << endl;
    } else {
        while (!pilhaParesVetor.estaVazia()) {
            cout << pilhaParesVetor.desempilhar() << " ";
        }
        cout << endl;
    }

    return 0;
}