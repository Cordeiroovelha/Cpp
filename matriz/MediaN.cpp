// programa que calcula media de n numeros
// Autoria de murilo Juttel
// escrito em c++

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    vector<float> array;
    size_t indice;
    char resp = 's';

    do {
        cout << "Quantos numeros na cadeia? ";
        cin >> indice;
        cin.ignore(80, '\n');
        array.resize(indice);
        cout << endl;
        for (size_t i = 0; i < indice; i++){
            cout << "Entre o " << i+1 << "o valor: ";
            cin >> array[i];
            cin.ignore(80, '\n');
        }

        float soma = 0;

        for (size_t i = 0; i < indice; i++){
            soma = soma + array[i];
        }

        // float mediana = 0;

        // if (indice % 2 == 0){
	    //     float m1 = array[indice / 2 -1];
        //     float m2 = array[indice / 2];
        //     mediana  = array[(m1 + m2) / 2];
	    // }
        // else
        //     mediana = array[indice / 2];

        cout << endl;
        cout << "soma: " << soma << endl;
        cout << "Media: " << soma/indice << endl;
        // cout << "Mediana: " << mediana 	<< endl;
        cout << string(80, '-') << endl;
        cout << "Deseja continuar? ";
        cin.get(resp);
        cin.ignore(80, '\n');

    } while(resp != 'n' or 'N');
    

    cout << endl;
    cout << "Aperte <enter> para terminar";
    cin.get();
    return 0;
}
