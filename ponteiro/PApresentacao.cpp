// leitor de idade e nome utilizando ponteiro

#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int16_t idade;
    int16_t *Pidade = &idade;

    string nome;
    string *Pnome = &nome;

    cout << "Digite o seu nome: ";
    getline(cin, *Pnome);
    cout << "Digite a sua idade: ";
    cin >> *Pidade;
    cin.ignore(80, '\n');

    cout << endl;
    cout << "Ola " << *Pnome << ", voce tem " << *Pidade << " anos!!" << endl;
    cout << endl << endl;
    string(80, '-');
    cout << "Idade localizada no endereco: " << Pidade << endl;
    cout << "Nome localizado no endereco: " << Pnome << endl;

    cout << endl;
    cout << "Aperte <enter> para continuar...";
    cin.get();
    return 0;
}