// entradamaisde18.cpp

#include <iostream>
using namespace std;

int main(void){
    int32_t idade, acompanhante;

    cout << "Idade da pessoa: "; cin >> idade;
    cin.ignore(80, '\n');
	cout << endl;
	
    if (idade < 18){
        cout << "Esta com acompanhante? "; cin >> acompanhante;
        cin.ignore(80, '\n');
        cout << endl;
        if (acompanhante == 1)
            cout << "Entrada autorizada" << endl;
        else
            cout << "entrada recusada" << endl; 
    }
    else
        cout << "entrada autorizada" << endl;

    cout << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
    return 0;
}
