#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string formatarBiblio(const string& nome) {
    istringstream ss(nome);
    vector<string> partes;
    string palavra;
    while (ss >> palavra)
        partes.push_back(palavra);

    if (partes.size() < 2) return nome;

    // Sobrenome em maiúsculas
    string sobrenome = partes.back();
    transform(sobrenome.begin(), sobrenome.end(),
               sobrenome.begin(), ::toupper);

    // Prenome (primeiro nome) completo
    string resultado = sobrenome + ", " + partes[0];

    // Nomes do meio abreviados (índice 1 até penúltimo)
    for (int i = 1; i < (int)partes.size() - 1; i++) {
        resultado += " ";
        resultado += (char)toupper(partes[i][0]);
        resultado += ".";
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
            cout << formatarBiblio(linha) << "\n";
    }

    arq.close();
    return 0;
}