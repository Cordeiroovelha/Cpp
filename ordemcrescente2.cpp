// ordemcrescente2.cpp

#include <iostream>
using namespace std;

int main(void){
    int32_t a, b, c, r;

    cout << "escolha um valor <A>: "; cin >> a;
    cin.ignore(80, '\n');
    cout << "escolha um valor <B>: "; cin >> b;
    cin.ignore(80, '\n');
    cout << "escolha um valor <C>: "; cin >> c;
    cin.ignore(80, '\n');

    if (a > b){
        r = a;
        a = b;
        b = r;
    }
    if (a > c){
        r = a;
        a = c;
        c = r;
    }
    if (b > c){
        r = b;
        b = c;
        c = r;
    }
    

    cout << "os numeros em forma ordenada ficam --> " << a << " , " << b << " , " << c << endl;
    
    cout << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
    return 0;
}
