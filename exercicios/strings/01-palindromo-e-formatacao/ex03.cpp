#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string formatarAgenda(const string& nome) {
    istringstream ss(nome);
    vector<string> partes;
    string palavra;

    while (ss >> palavra)
        partes.push_back(palavra);

    if (partes.size() < 2) return nome;

    string sobrenome = partes.back();
    string resultado = sobrenome + ", ";
    for (int i = 0; i < (int)partes.size() - 1; i++) {
        if (i > 0) resultado += " ";
        resultado += partes[i];
    }
    return resultado;
}

int main() {
	setlocale(LC_ALL, "");
	
    ifstream arq("nomes.txt");
    if (!arq.is_open()) {
        cerr << "Erro: arquivo não encontrado.\n";
        return 1;
    }

    string linha;
    while (getline(arq, linha)) {
        if (!linha.empty())
            cout << formatarAgenda(linha) << "\n";
    }

    arq.close();
    return 0;
}