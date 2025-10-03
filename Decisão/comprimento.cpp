// comprimento.cpp

#include <iostream>
#include <ciso646>
#include <string>
using namespace std;

int main(void){
    char sexo;
    string nome;

    cout << "Digite o seu nome: "; cin >> nome;
    cin.ignore(80, '\n');
    cout << "Digite seu genero (M/F/N): "; cin >> sexo;

    cout << "Bem vindo ";
    if (sexo == 'M' or sexo == 'm')
        cout << "senhor ";
    if (sexo == 'F' or sexo == 'f')
        cout << "senhora ";
    if (sexo == 'N' or sexo == 'n')
        cout << "ser vivo ";
    cout << nome << ".";

    cout << endl;
    cout << "aperte <enter> para continuar";
	cin.ignore();
    cin.get();
    return 0;
}

