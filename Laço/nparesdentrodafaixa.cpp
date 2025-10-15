// nparesdentrodafaixa.cpp

#include <iostream>
using namespace std;

int main(void) {
    int32_t inicio, fim;
    char resp {'s'};

    while (resp == 's') {

        cout << "informe o valor inicial da faixa: "; cin >> inicio;
        cin.ignore(80, '\n');
        cout << "informe o valor final da faixa: "; cin >> fim;
        cin.ignore(80, '\n');

        while (inicio <= fim) {
            if (inicio % 2 == 0) {
                cout << inicio << " ";
            }
            inicio++;
        }
        
        cout << endl << endl << endl; 
        cout << "deseja recomecar [s/n]? ";
        cin.get(resp);
        cin.ignore();
        cout << endl << endl << endl;
    } 

    cout << endl;
    cout << "aperte <enter> para encerrar o programa" << endl;
    cin.get();
    return 0;
}
