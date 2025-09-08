// login.cpp

#include <iostream>
using namespace std;

int main(void) {
    string login, senha;
    const string login_correto = "admin";
    const string senha_correta = "12345";
    int16_t tentativas = 3;
    bool autenticado = false;

    while (tentativas > 0 and autenticado == false) {
    
        cout << "Login no servidor" << endl;
        cout << "**********************" << endl;
        cout << "Voce tem " << tentativas << " tentativas" << endl;
        cout << "**********************" << endl << endl;
        cout << "login: "; cin >> login;
        cin .ignore(80, '\n');
        cout << "senha: "; cin >> senha;
        cin .ignore(80, '\n');

        if (login == login_correto and senha == senha_correta) {

            cout << endl << "acesso permitido" << endl;
            autenticado = true;
        }
        else {
            cout << endl << "login ou senha incorretos" << endl << endl;
            tentativas--;
        }

    }

    if (autenticado == false) {
        cout << "numero de tentativas excedido" << endl;
    }

    cout << endl;
    cout << "aperte <enter> para finalizar o programa" << endl;
    cin.get();
    return 0;
}
