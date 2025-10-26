// programa que faz adição utilizando ponteiro

#include <iostream>
#include <string>
using namespace std;

int main(void) {
    float A, B, R;
    float *Pa = &A;
    float *Pb = &B;
    float *Pr = &R;

    cout << "Digite um valor A: ";
    cin >> *Pa;
    cin.ignore(80, '\n');
    cout << "Digite um valor B: ";
    cin >> *Pb;
    cin.ignore(80, '\n');

    *Pr = *Pa + *Pb;

    cout << endl;
    cout << "O resultado da adicao " << *Pa << " + " << *Pb << " = " << *Pr << endl;

    cout << endl;
    string(80, '-');
    cout << "Valor " << *Pa << " localizado no endereco: " << Pa << endl;
    cout << "Valor " << *Pb << " localizado no endereco: " << Pb << endl;
    cout << "Valor " << *Pr << " localizado no endereco: " << Pr << endl;
    cout << endl;
    cout << "Aperte <enter> para continuar...";
    cin.get();
    return 0;
}