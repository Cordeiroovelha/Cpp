// maiorquecem.cpp

#include <iostream>
using namespace std;

int main(void){
    int32_t a, b, c, r;

    cout << "escreva um valor <A>:"; cin >> a;
    cin.ignore(80, '\n');
    cout << "escreva um valor <B>:"; cin >> b;
    cin.ignore(80, '\n');
    cout << "escreva um valor <C>:"; cin >> c;
    cin.ignore(80, '\n');

    r = a + b + c;

    if (r >= 100)
        cout << "a soma deu MAIS que 100";
    else
        cout << "a soma deu MENOS que 100";

    cout << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
}

