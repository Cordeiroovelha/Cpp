// maiorque3.cpp

#include <iostream>
#include <ciso646>
using namespace std;

int main(void){
    int32_t n;

    cout << "Selecione um valor <N>: "; cin >> n;
    cin.ignore(80, '\n');
    if (not(n > 3))
        cout << "o valor e MENOR que 3." << endl;
    else
        cout << "o valor e MAIOR que 3." << endl;

    cout << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
    return 0;
}
