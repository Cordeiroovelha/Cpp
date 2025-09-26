// ordemcrescente.cpp

#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int32_t a, b, c;

    cout << "escolha um valor <A>: "; cin >> a;
    cin.ignore(80, '\n');
    cout << "escolha um valor <B>: "; cin >> b;
    cin.ignore(80, '\n');
    cout << "escolha um valor <C>: "; cin >> c;
    cin.ignore(80, '\n');

    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);

    cout << "os numeros em forma ordenada ficam --> " << a << " , " << b << " , " << c << endl;
    
    cout << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
    return 0;
}
