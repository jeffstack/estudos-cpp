#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord = {(short)x, (short)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    string msg;
    cout << "Digite a mensagem: ";
    getline(cin, msg);

    int largura = 80;
    int colInicio = (largura - (int)msg.size()) / 2;
    if (colInicio < 0) colInicio = 0;

    // Exibe mensagem centralizada na linha 5 (índice 4)
    gotoxy(colInicio, 4);
    cout << msg;
    Sleep(800);

    // Cascata: cada letra cai da linha 5 até linha 20
    for (int i = 0; i < (int)msg.size(); i++) {
        for (int linha = 4; linha <= 19; linha++) {
            gotoxy(colInicio + i, linha);
            cout << msg[i];
            Sleep(40);
            gotoxy(colInicio + i, linha);
            cout << ' '; // apaga rastro
        }
        // Deixa a letra na posição final
        gotoxy(colInicio + i, 19);
        cout << msg[i];
    }

    gotoxy(0, 22);
    return 0;
}