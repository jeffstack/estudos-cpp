#include <iostream>
#include <string>
#include <vector>
#include <locale.h>
#include <iomanip>
#include <limits>

using namespace std;

// Classe Data
class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    // Construtor
    Data(int dia = 1, int mes = 1, int ano = 1900) {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }

    // Getters
    int getDia() const {
        return dia;
    }
    int getMes() const {
        return mes;
    }
    int getAno() const {
        return ano;
    }

    // Setters
    void setDia(int dia) {
        this->dia = dia;
    }
    void setMes(int mes) {
        this->mes = mes;
    }
    void setAno(int ano) {
        this->ano = ano;
    }

    // Método para exibir a data
    void exibirData() const {
        cout << setfill('0') << setw(2) << dia << "/"
             << setfill('0') << setw(2) << mes << "/"
             << setfill('0') << setw(4) << ano;
    }
};

// Classe Contato
class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    // Construtor
    Contato(string email = "", string nome = "", string telefone = "", Data dtnasc = Data())
        : email(email), nome(nome), telefone(telefone), dtnasc(dtnasc) {}

    // Getters
    string getEmail() const {
        return email;
    }
    string getNome() const {
        return nome;
    }
    string getTelefone() const {
        return telefone;
    }
    Data getDtnasc() const {
        return dtnasc;
    }

    // Setters
    void setEmail(string email) {
        this->email = email;
    }
    void setNome(string nome) {
        this->nome = nome;
    }
    void setTelefone(string telefone) {
        this->telefone = telefone;
    }
    void setDtnasc(Data dtnasc) {
        this->dtnasc = dtnasc;
    }

    // Método para calcular a idade
    int idade() const {
        // Utilizando o ano de 2026 para o cálculo da idade
        return 2026 - dtnasc.getAno();
    }

    // Método para exibir o contato
    void exibirContato() const {
        cout << "Nome: " << nome
             << ", Email: " << email
             << ", Telefone: " << telefone
             << ", Data de Nascimento: ";
        dtnasc.exibirData();
        cout << ", Idade: " << idade() << endl;
    }
};

int main() {
    setlocale(LC_ALL, ""); // Para garantir a exibição correta de caracteres especiais

    vector<Contato> contatos;
    contatos.reserve(5);

    cout << "Cadastro de 5 Contatos:" << endl;

    for (int i = 0; i < 5; ++i) {
        string email, nome, telefone;
        int dia, mes, ano;

        cout << "\nContato #" << (i + 1) << endl;

        cout << "Email: ";
        getline(cin, email);

        cout << "Nome: ";
        getline(cin, nome);

        cout << "Telefone: ";
        getline(cin, telefone);

        cout << "Data de Nascimento (dia mes ano): ";
        cin >> dia >> mes >> ano;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpar o buffer do teclado

        Data dtnasc(dia, mes, ano);
        Contato contato(email, nome, telefone, dtnasc);
        contatos.push_back(contato);
    }

    cout << "\n--- Contatos Cadastrados ---" << endl;
    for (const auto& contato : contatos) {
        contato.exibirContato();
    }

    return 0;
}
