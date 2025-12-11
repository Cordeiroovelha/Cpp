#include <iostream>
#include <string>
using namespace std;

int main(void){
    int32_t Idade;
    int32_t *Pidade = &Idade;

    cout << "=== Entrada Balada(+18) ===" << endl;
    cout << "\nQual a sua idade: ";
    cin >> *Pidade;
    cin.ignore(80, '\n');

    if (*Pidade >= 18)
        cout << "Entrada LIBERADA" << endl;
    else
        cout << "Entrada NEGADA" << endl;

    cout << "Aperte <enter> para encerrar o programa";
    cin.get();
    return 0;
}