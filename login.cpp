// validaçao de login
// escrito em c++
// autor: Murilo Juttel Cordeiro

#include <iostream>
#include <string>
using namespace std;


int main(void){
	bool validacao = false;
    uint32_t idade;
    string nome, email;

    cout << "Pagina de Login" << endl;
    cout << "\n";
    while (validacao == false) {
        cout << "Nome: "; getline(cin, nome);
        if (nome.length() >= 5 and nome.length() <= 25){
            validacao = true;
            cin.ignore(80, '\n');
        }
        else {
            cout << "Nome invalido, tente novamente";
            cin.ignore(100, '\n');
        }
    }
	
	validacao = false;
	
    while (validacao == false) {
        cout << "idade: "; cin >> idade;
        if (idade >= 18 and idade <= 30) {
            validacao = true;
            cin.ignore(80, '\n');
        }
        else {
            cout << "Idade invalida tente novamente" << endl;
            cin.ignore(100, '\n');
        }
    }
    
    validacao = false;
	
    while (validacao == false) {

        size_t pos = email.find('@');

        cout << "email: "; getline(cin, email);
        if (pos != string::npos and email.length() > 5) {
            validacao = true;
            cin.ignore(80, '\n');
        }
        else {
            cout << "Idade invalida tente novamente" << endl;
            cin.ignore(100, '\n');
        }
    }

    cout << "Dados apresentados" << endl;
    cout << "\n";
    cout << nome << endl;
    cout << idade << endl;
    cout << email << endl;

    cout << endl;
    cout << "Aperte <enter> para encerrar";
    cin.get();
    return 0;
}
