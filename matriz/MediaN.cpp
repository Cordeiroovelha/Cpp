// programa que calcula media de n numeros
// Autoria de murilo Juttel
// escrito em c++

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Media{
    vector<float> array;
    size_t indice;
    size_t frequencia;
};


void MediaComposta(void) {

}


int main(void){
    char resp = 's';
    Media Dados;

    cout << setprecision(2) << fixed << right;

    do {
        cout << "Quantos numeros na cadeia? ";
        cin >> Dados.indice;
        cin.ignore(80, '\n');
        Dados.array.resize(Dados.indice);
        cout << endl;
        for (size_t i = 0; i < Dados.indice; i++){
            cout << "Entre o " << i+1 << "o valor: ";
            cin >> Dados.array[i];
            cin.ignore(80, '\n');
        }

        float soma = 0;

        for (size_t i = 0; i < Dados.indice; i++){
            soma = soma + Dados.array[i];
        }

        float mediana = 0;

        if (Dados.indice % 2 == 0){
            int32_t meio1 = Dados.indice / 2 - 1;
            int32_t meio2 = Dados.indice / 2;
            mediana  = (Dados.array[meio1] + Dados.array[meio2]) / 2;
	    }
        else
            mediana = Dados.array[Dados.indice / 2];

        cout << endl;
        cout << "soma: " << soma << endl;
        cout << "Media: " << setw(5) << soma/Dados.indice << endl;
        cout << "Mediana: " << mediana 	<< endl;
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
