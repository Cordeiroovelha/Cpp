// numeroprimo.cpp
// auto: Murilo Juttel Cordeiro
// escrito em C++

#include <iostream>
#include <ciso646>
#include <cctype>
using namespace std;

int main(void) {
    char resp {'S'};

    while (std::toupper(resp) == 'S') {        
        int32_t n;
        bool primo {false};
        int32_t divisor {2};

        cout << "informe um numero inteiro positivo maior que 1: "; cin >> n;
        cin.ignore(80, '\n');

        if (n <= 1) 
            cout << "numero invalido" << endl;
        else
            primo = true;            
        
        while (divisor <= n and primo == true) {

            if (n % divisor == 0 and divisor != n) 
                primo = false;
            divisor++;
        }

        if (primo == true)
            cout << n << " e primo" << endl;
        else
            cout << n << " nao e primo" << endl;

        cout << endl << endl << endl;
        cout << "Deseja verificar outro numero [s/n]? ";
        cin.get(resp);
        cin.ignore();
        cout << endl << endl << endl;

    }

    cout << endl;
    cout << "aperte <enter> para finalizar o programa" << endl;
    cin.get();
    return 0;
}
