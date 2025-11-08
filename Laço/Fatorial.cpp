// programa que calcula fatorial de n

#include <iostream>
using namespace std;

int main(void) {
    int32_t n;
    unsigned long fatorial = 1;

    while (true) {
        cout << "Digite um numero inteiro e nao negativo: ";
        if (cin >> n && n >= 0) {
            break;
        }
        cout << "Entrada invalida. Tente novamente." << endl;
        cin.clear();
        cin.ignore(100, '\n');
    }
    for (int32_t i = 1; i <= n; i++) {
        fatorial *= i;
    }
    cout << "\nFatorial de " << n << " = " << fatorial << endl;

    cout << endl;
    cout << "Aperte <enter> para continuar...";
    cin.get();
    return 0;
}