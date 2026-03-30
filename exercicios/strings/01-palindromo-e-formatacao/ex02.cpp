#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	
    string frase;
    cout << "Digite a mensagem: ";
    getline(cin, frase);

    // Remove espaços e converte para maiúsculo
    string limpa = "";
    for (int i = 0; i < frase.size(); i++) 
	{
    	char c = frase[i];
    	if (!isspace((unsigned char)c))
		{
			   limpa += toupper((unsigned char)c);	
		}
	}

    // Verifica palíndromo com std::reverse
    string invertida = limpa;
    reverse(invertida.begin(), invertida.end());

    if (limpa == invertida)
        cout << "\"" << frase << "\" É um palíndromo!\n";
    else
        cout << "\"" << frase << "\" NÃO é um palíndromo.\n";

    return 0;
}