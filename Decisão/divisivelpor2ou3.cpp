// divisivelpor2ou3.cpp

#include <iostream>
using namespace std;

int main(void){
    int32_t a, b , c, d , r;
    
    cout << "escreva um valor <A>:"; cin >> a;
    cin.ignore(80, '\n');
    cout << "escreva um valor <B>:"; cin >> b;
    cin.ignore(80, '\n');
    cout << "escreva um valor <C>:"; cin >> c;
    cin.ignore(80, '\n');
    cout << "escreva um valor <D>:"; cin >> d;
    cin.ignore(80, '\n');

    cout << "valores divisiveis por 2 --> ";
    if (r = a % 2; r == 0)
        cout << a << " | ";
    if (r = b % 2; r == 0)
        cout << b << " | ";
    if (r = c % 2; r == 0)
        cout << c << " | ";
    if (r = d % 2; r == 0)
        cout << d << " | ";

    cout << endl << endl;

    cout << "valores divisiveis por 3 --> ";
    if (r = a % 3; r == 0)
        cout << a << " | ";
    if (r = b % 3; r == 0)
        cout << b << " | ";
    if (r = c % 3; r == 0)
        cout << c << " | ";
    if (r = d % 3; r == 0)
        cout << d << " | ";

    cout << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
    return 0;
}
