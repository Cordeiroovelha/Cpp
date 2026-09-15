/*
Escreva um programa que solicite a entrada da idade e da altura de 10 pessoas. Armazene
as informações dentro de vetores específicos. Em seguida, apresente os valores da idade e da
altura de cada pessoa, na ordem inversa da que foram fornecidas.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Pessoa {
    int idade;
    double altura;
};

int main(void){
    vector<Pessoa> pessoas(10);

    for(size_t i = 0; i < pessoas.size(); i++){
        cin >> pessoas[i].idade;
        cin >> pessoas[i].altura;
    }

    for (int i = (int)pessoas.size() - 1; i >= 0; i--) {
        cout << "Pessoa " << i + 1 << ':' << endl;
        cout << "Idade..: " << pessoas[i].idade << endl;
        cout << "Altura.: " << pessoas[i].altura << endl;
    }
    
    return 0;
}