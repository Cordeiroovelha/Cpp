// estrela.cpp

#include <iostream>
using namespace std;

int main(void) {
    int32_t b;
    cout << "Qual o tamanho da base? ";
    cin >> b;
    cin.ignore(80, '\n');

    for (int32_t i = 0; i <= b; i++){
        for (int32_t j = 0; j <= i; j++)
            cout << "*";
        cout << endl;
    }
    cout << "Aperte <enter> para encerrar ...";
    cin.get();
    return 0;
}