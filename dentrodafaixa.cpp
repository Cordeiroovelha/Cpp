// dentrodafaixa.cpp

#include <iostream>
#include <ciso646>
using namespace std;

int main(void){
    int32_t n;

    cout << "faixa definida: 1-9 ";
    cout << "Escolha um valor <N>: "; cin >> n;
    cin.ignore(80, '\n');

    if (n >= 1 and n <= 9)
        cout << "o numero esta DENTRO da faixa definida";
    else
        cout << "o numero esta FORA da faixa definida";

    cout << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
    return 0;
}
