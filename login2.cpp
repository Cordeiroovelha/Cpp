// forma alternativa de validar login
// escrito em C++
// Autor Murilo Juttel Cordeiro

#include <iostream>
using namespace std;

int16_t validacao = 0;

float validar_nome(string nome, int16_t validacao) {
    if (nome.length() >= 5 or nome.length() <= 25)
        return validacao += 1;
    else
        return 0;
}

int main(void) {
    int32_t idade;
    string nome, email;
    uint8_t resposta = 1;

    while (resposta == 1) {
        while (true) {
            cout << "Nome: ";
            if (cin >> nome)
                break;
            else {
                cout << "Nome escrito de maneira errada" << endl;
                cin.ignore(80, '\n');
            }
        }
        validar_nome(nome, validacao);
    }

    cout << endl;
    cout << "Aperte <enter> para encerrar";
    cin.get();
    return 0;
}
