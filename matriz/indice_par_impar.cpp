// indice_par_impar
// autoria de murilo Juttel Cordeiro

#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

int main(void) {

    array<int32_t, 5> a, b;

    cout << right;
    cout << "Checagem de indice" << endl;
    cout << endl;

    // entrada de dados
    for (size_t i = 0; i < a.size(); ++i) {
        cout << "Informe o " << setw(2) << i+1 << "o elemento: ";
        cin >> a[i];
        cin.ignore(80, '\n');
    }

    // procedimento
    for (size_t i = 0; i < a.size(); ++i) {
        if ((i + 1) % 2 == 0) 
            b[i] = a[i] + 5;
        else 
            b[i] = a[i] * 2;
    }

    // apresentação da matriz
    for (size_t i = 0; i < a.size(); ++i) {
        cout << '\n';
        cout << setw(2) << i+1 << " --> " << b[i]; 
    }

    cout << endl;
    cout << "Aperte <enter> para encerrar...";
    cin.get();
    return 0;
}
