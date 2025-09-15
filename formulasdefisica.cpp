// Principais formulas de fisicas
// Autoria de: Murilo Juttel Cordeiro
// Escrito em C++

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float r;

void pausa(void) {
    cout << endl << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
    cout << endl;
}

void saida(void) {
    cout << "o volume do objeto --> " << setw(12) << r << endl;
    pausa();
}

void rotmov(void) {
    uint16_t resp{0};
    
    while (resp != 4){
        cout << "\n" << endl;
        cout << "------------" << endl;
        cout << " Movimentos " << endl;
        cout << "------------" << endl;
        cout << endl;
        cout << "qual sera a formula a ser calculada?" << endl;
        cout << "[1] - equação de Torricelli" << endl;
        cout << "[2] - equação de Movimento Retilíneo Uniforme (MRU)" << endl;
        cout << "[3] - equação de Movimento Retilíneo Uniforme Variado (MRUV)" << endl;
        cout << "[4] - voltar para o menu principal" << endl;

        while (true) {
            cout << "escolha uma opcao: ";
            if (cin >> resp)
                break;
            else {
                cout << "opcao invaida tente novamente" << endl;
                cin.clear();
                cin.ignore(10000 , '\n');
            }
        } 
        cin.ignore(80, '\n');
    
        if (resp != 4){
            switch (resp) {
                case 1: rottorricelli()     break;
                case 2: rotmru()            break;
                case 3: raotmruv()          break;
                default: cout << "opçao invalida tente novamente";
                pausa();                    break;
            }    
        }
    }
}

void roteletro(void) {
    uint16_t resp{0};
    
    while (resp != 4){
        cout << "\n" << endl;
        cout << "-------------" << endl;
        cout << " Eetricidade " << endl;
        cout << "-------------" << endl;
        cout << endl;
        cout << "qual sera a formula a ser calculada?" << endl;
        cout << "[12 - lei de ion" << endl;
        cout << "[2] - potencial eletrica" << endl;
        //corrigir
        cout << "[3] - Energia" << endl;
        cout << "[4] - voltar para o menu principal" << endl;

        while (true) {
            cout << "escolha uma opcao: ";
            if (cin >> resp)
                break;
            else {
                cout << "opcao invaida tente novamente" << endl;
                cin.clear();
                cin.ignore(10000 , '\n');
            }
        } 
        cin.ignore(80, '\n');
    
        if (resp != 4){
            switch (resp) {
                //corrigir
                case 1: rottorricelli()     break;
                case 2: rotmru()            break;
                case 3: raotmruv()          break;
                default: cout << "opçao invalida tente novamente";
                pausa();                    break;
            }    
        }
    }
}


int main(void) {
    uint16_t resp{0};
    cout << setprecision(2) << fixed << right;

    //looping principal

    while (resp != 5) {
        cout << "-----------------------" << endl;
        cout << " Calculadora de fisica " << endl;
        cout << "-----------------------" << endl;
        cout << '\n' << endl;

        cout << "qual sera a area da fisica?" << endl;
        cout << "[1] - Movimentos" << endl;
        cout << "[2] - Eletricidade" << endl;
        cout << "[3] - Energia" << endl;
            cout << "[6] - Energia mecanica" << endl;
            cout << "[6] - Energia cinetica" << endl;
            cout << "[6] - Energia potencial gravitacional" << endl;
            cout << "[6] - Energia potencial elastica" << endl;
        cout << "[4] - Sair do programa" << endl;

        while (true) {
            cout << "escolha uma opcao: ";
            if (cin >> resp)
                break;
            else {
                cout << "opcao invaida tente novamente" << endl;
                cin.clear();
                cin.ignore(10000 , '\n');
            }
        } 
        cin.ignore(80, '\n');

        if (resp != 4) {
            switch (resp) {
                case 1: rotmov();    break;
                case 2: roteletro(): break;
                case 3: rotenerg();  break;
                default:
                    cout << "opçao invalida";
                    pausa();         break;
            }
        }
    }
    cout << endl;
    cout << "aperte <enter> para encerrar";
    cin.ignore();
    cin.get();
    return 0;
}
