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
        cout << "Nome: "; cin >> nome;
        cin.ignore(80, '\n');
        if (nome.length() >= 5 and nome.length() <= 30)
            validacao = true;           
        else 
            cout << "Nome invalido, tente novamente";
    }
	
	validacao = false;
	
    while (validacao == false) {
        cout << "idade: "; 
        cin >> idade;
        cin.ignore(80, '\n');
        if (idade >= 18 and idade <= 30) 
            validacao = true;
        else 
            cout << "Idade invalida tente novamente" << endl;
    }
    
    validacao = false;
	
    while (validacao == false) {

        size_t pos = email.find('@');

        cout << "email: "; 
        cin >> email;
        cin.ignore(80, '\n');
        if (pos != string::npos and email.length() > 5)
            validacao = true;
        else
            cout << "Email invalida tente novamente" << endl;
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
