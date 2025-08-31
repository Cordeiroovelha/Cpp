//diferencaentredoisnumeros.cpp

#include <iostream>
#include <print>
using namespace std;

int main(void){
    int32_t a, b;

    println("escreva um valor <A>: ");
    cin >> a;
    cin.ignore(80, '\n');
    println("escreva um valor <B>: ");
    cin >> b;
    cin.ignore(80, '\n');

    if (a < b)
        cout << "a diferenca entre os numeros --> " << b - a;
    else
        cout << "a diferenca entre os numeros --> " << a - b;

    cout << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
    return 0;
}
