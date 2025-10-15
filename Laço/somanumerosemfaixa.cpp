// soma de n numeros dentro de uma faixa

#include <iostream>
using namespace std;

int main(void) {
    int32_t inicio, fim, soma {0};

    cout << "Digite o numero inicial da faixa: ";
    cin >> inicio;
    cin.ignore(80, '\n');
    cout << "Digite o numero final da faixa: ";
    cin >> fim;
    cin.ignore(80, '\n');

    for (int32_t i = inicio; i <= fim; i++) {
        soma += i;
    }

    /* 
        exemplo de laco while

        while (inicio <= fim) {
            soma += i;
            i++;
        }      
    */

    cout << "\nA soma dos numeros de " << inicio << " a " << fim << " --> " << soma << endl;
    cout << endl;
    cout << "Aperte <enter> para encerrar o programa";
    cin.get();
    return 0;
}