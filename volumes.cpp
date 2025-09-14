// volumes.cpp
// autoria de Murilo Juttel Cordeiro
// escrito em c++

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float r;
const float pi = 3.14;

void pausa(void) {
    cout << endl;
    cout << "Aperte <enter> para continuar";
    cin.get();
}

void saida(void) {
    cout << "o volume do objeto --> " << setw(12) << r << endl;
    pausa();
}

void rotcilindro(void) {
    float raio, altura;
    
    cout << "Digite o RAIO do cilindro:";  cin >> raio;
	cin.ignore(80, '\n');
	cout << "Digite a ALTURA do cilindro"; cin >> altura;
	cin.ignore(80, '\n');

    r = pi * pow(raio,2) * altura;
    saida();
}

void rotretangulo(void) {
    float altura, comprimento, largura;

    cout << "Escreva o COMPRIMENTO da caixa:"; cin >> comprimento;
	cin.ignore(80, '\n');
	cout << "Escreva a LARGURA da caixa ...:"; cin >> largura;
	cin.ignore(80, '\n');
	cout << "Escreva a ALTURA da caixa ....:"; cin >> altura;
	cin.ignore(80, '\n');
	
	r = altura * comprimento * largura;
    saida();
}

void rotesfera(void) {
    float raio;

    cout << "Digite o RAIO da esfera:"; cin >> raio;
	cin.ignore(80, '\n');

    r = (4.0 / 3.0) * pi * pow(raio, 3);
    saida();
}

int main(void) {
    uint16_t opcao = 0;
    cout << setprecision(2) << fixed << right;
    
    while (opcao != 4) {
        cout << "----------------------" << endl;
        cout << "calculadora de volumes" << endl;
        cout << "----------------------" << endl;
        cout << "\n" << endl;

        cout << "selecione o tipo de objeto" << endl;
        cout << "[1] - cilindro" << endl;
        cout << "[2] - retangulo" << endl;
        cout << "[3] - esfera" << endl;
        cout << "[4] - encerrar programa" << endl;

        while (true){
            cout << "\nEscolha uma opcao: ";
            if (cin >> opcao)
                break;
            else {
                cout << "\nOpcao invalida tente novamente";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }

        if (opcao != 4) {
            switch (opcao) {
                case 1: rotcilindro();   break;
                case 2: rotretangulo();  break;
                case 3: rotesfera();     break;
                default: 
                    cout << "opcao invalida";
                    pausa();            break;
            }
        }
    }
    cout << endl;
    cout << "Aperte <enter> para encerrar";
    cin.get();
    return 0;
}
