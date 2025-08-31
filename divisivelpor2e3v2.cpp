// divisivelpor2e3v2.cpp

#include <iostream>
#include <ciso646>
using namespace std;

int main(void){
    int32_t a, b , c, d , r1, r2, s;
    s = 0;
    
    cout << "escreva um valor <A>:"; cin >> a;
    cin.ignore(80, '\n');
    cout << "escreva um valor <B>:"; cin >> b;
    cin.ignore(80, '\n');
    cout << "escreva um valor <C>:"; cin >> c;
    cin.ignore(80, '\n');
    cout << "escreva um valor <D>:"; cin >> d;
    cin.ignore(80, '\n');

    cout << "valores divisiveis por 2 e 3 --> ";
    r2 = a % 3;
    r1 = a % 2;
    if (r1 == 0 and r2 == 0){
        cout << a << " | ";
        s += 1;
    }
    r1 = b % 2;
    r2 = b % 3;
    if (r1 == 0 and  r2 == 0){
        cout << b << " | ";
        s += 1;
    }
    r1 = c % 2;
    r2 = c % 3;
    if (r1 == 0 and r2 == 0){
        cout << c << " | ";
        s += 1;
    }
    r1 = d % 2;
    r2 = d % 3;
    if (r1 == 0 and r2 == 0){
        cout << d << " | ";
        s += 1;
    }
	if (s == 0)
		cout << "nenhum";
	
    cout << endl << endl;
    cout << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
    return 0;
}
