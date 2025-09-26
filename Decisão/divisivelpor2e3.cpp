// divisivelpor2e3.cpp

#include <iostream>
using namespace std;

int main(void){
    int32_t a, b , c, d , r1, r2;
    
    cout << "escreva um valor <A>:"; cin >> a;
    cin.ignore(80, '\n');
    cout << "escreva um valor <B>:"; cin >> b;
    cin.ignore(80, '\n');
    cout << "escreva um valor <C>:"; cin >> c;
    cin.ignore(80, '\n');
    cout << "escreva um valor <D>:"; cin >> d;
    cin.ignore(80, '\n');

    cout << "valores divisiveis por 2 e 3 --> ";
    if (r1 = a % 2; r1 == 0){
        if (r2 = a % 3; r2 == 0)
            cout << a << " | ";
    }        
    if (r1 = b % 2; r1 == 0){
        if (r2 = b % 3; r2 == 0)
            cout << b << " | ";
    }
    if (r1 = c % 2; r1 == 0){
        if (r2 = c % 3; r2 == 0)
            cout << c << " | ";
    }
    if (r1 = d % 2; r1 == 0){
        if (r2 = d % 3; r2 == 0)
            cout << d << " | ";
    }
    cout << endl << endl;

    cout << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
    return 0;
}
