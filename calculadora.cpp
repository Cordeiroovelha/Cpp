// calculadora.cpp
// autoria de Murilo Juttel Cordeiro
// escrito em c++

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
using namespace std;

float r, a, b;

// rotina de pausa e recomeço do looping principal

void pausa(void){
    cout << endl << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
    cout << endl;
}

// rotina de entrada de dados

void entrada(void){7

    // confirmação de entrada numerica

    while (true) {
            cout << "escolha um numero <A>: ";
            if (cin >> a)
                break;
            else {
                cout << "escreva apenas numeros\nTente Novamente" << endl;
                cin.clear();
                cin.ignore(10000 , '\n');
            }
        } 
        cin.ignore(80, '\n');
        
    while (true) {
            cout << "escolha um numero <B>: ";
            if (cin >> b)
                break;
            else {
                cout << "escreva apenas numeros\nTente Novamente" << endl;
                cin.clear();
                cin.ignore(10000 , '\n');
            }
        } 
        cin.ignore(80, '\n');
}

// rotina de saida de dados

void saida(void) {
    cout << "Resuldado -----------> " << setw(4) << r;
    pausa();
}

// rotina de efetuamento de calculos

float calculo(float a, float b, char operador) {
    switch (operador){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        default:  return 0.0;
    }
}

// rotina de soma

void rotadd(void) {
    cout << endl;
    cout << "Operacao de adicao" << endl;
    entrada();
    r = calculo(a, b, '+');
    saida();
}

// rotina de subtraçao

void rotsub(void) {
    cout << endl;
    cout << "Operacao de subtracao" << endl;
    entrada();
    r = calculo(a, b, '-');
    saida();
}

// rotina de multiplicação

void rotmult(void) {
    cout << endl;
    cout << "Operacao de multiplicacao" << endl;
    entrada();
    r = calculo(a, b, '*');
    saida();
}

// rotina de divisão

void rotdiv(void) {
    cout << endl;
    cout << "Operacao de divisao" << endl;
    entrada();
    if (b == 0) {  // confirmação de divisão possivel
        cout << "operacao invalida tente novamente" << endl;
        pausa();
    }
    else {
        r = calculo(a, b, '+');
        saida();
    }
}

int main(void) {
    uint16_t opcao{0};
    cout << setprecision(2) << fixed << right;
    
    // looping principal

    while (opcao != 5) {

        cout << "***************" << endl;
        cout << "* CALCULADORA *" << endl;
        cout << "***************" << endl;
        cout << "\n" << endl;

        cout << "qual sera a operacao?" << endl;
        cout << "[1] - Adicao" << endl;
        cout << "[2] - Subtracao" << endl;
        cout << "[3] - Multiplicacao" << endl;
        cout << "[4] - Divisao" << endl;
        cout << "[5] - Sair do programa" << endl;

        while (true) {
            cout << "escolha uma opcao: ";
            if (cin >> opcao)
                break;
            else {
                cout << "opcao invaida tente novamente" << endl;
                cin.clear();
                cin.ignore(10000 , '\n');
            }
        } 
        cin.ignore(80, '\n');

        // chamada das subrotinas

        if (opcao != 5) {
            switch (opcao) {
                case 1: rotadd();    break;
                case 2: rotsub();    break;
                case 3: rotmult();   break;
                case 4: rotdiv();    break;
                default: 
                    cout << "opcao invalida";
                    pausa();     break;
            }
        }
    }

    // fim do programa

    cout << endl;
    cout << "Aperte <enter> para encerrar";
    cin.get();
    return 0;
}
