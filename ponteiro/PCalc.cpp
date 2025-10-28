// calculadora utilizando subrotinas com ponteiros
// autoria de Murilo Juttel Cordeiro
// escrito em c++

#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>
using namespace std;

float a, b, r;

void clear(void) {
    HANDLE tela;
    CONSOLE_SCREEN_BUFFER_INFO info;
    DWORD escrita = 0;
    tela = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(tela, &info);
    COORD pos = {0, 0};
    DWORD celulas = info.dwSize.X * info.dwSize.Y;
    FillConsoleOutputCharacter(tela, ' ', celulas, pos, &escrita);
    SetConsoleCursorPosition(tela, pos);
}

void erro(int cod) {
    switch (cod) {
        case 1:
            cout << "Operacao invalida. Tente novamente." << endl;
            break;
        case 2:
            cout << "Nao e possivel dividir por zero." << endl;
            break;
        default:
            cout << "Erro desconhecido." << endl;
    }
}

void pausa(void) {
    cout << endl << endl;
    cout << "Aperte <enter> para continuar...";
    cin.get();
    cout << endl;
}  

void Entrada(char op) {

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

    cout << endl;

    while (true) {
        cout << "Escolha um numero <B>" << endl;
        cout << a << " " << op << " ";
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

float calculo(float a, float b, char operador) {
    switch (operador) {
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return a * b;
        case '/' :if  (b != 0) 
                      return a / b; 
                  else {
                      erro(1); 
                      return 0.0;
                  }
        case '^' : return pow(a,b);
        case 'r' : return pow(a, 1.00 / b);
        default  : erro(1); return 0.0;
    }
}

void saida(void) {
    cout << "Resultado ------> " << setw(4) << r;
    cout << endl << endl;
    pausa();
}

void rotadd(void) {
    Entrada('+');
    r = calculo(a, b, '+');
    saida();
}

void rotsub(void) {
    Entrada('-');
    r = calculo(a, b, '-');
    saida();
}

void rotmult(void) {
    Entrada('*');
    r = calculo(a, b, '*');
    saida();
}

void rotdiv(void) {
    Entrada('/');
    r = calculo(a, b, '/');
    saida();
}

void rotpotencia(void) {
    Entrada('^');
    r = calculo(a, b, '^');
    saida();
}

void rotraiz(void) {
    float base, potencia;

    cout << endl;
    cout << "Operacao de radiciacao\n" << endl;
    cout << "Entre o valor da base: "; cin >> base;
    cin.ignore(80, '\n');
    cout << "Entre o valor do indice: "; cin >> potencia;
    cin.ignore(80, '\n');
    r = calculo(base, potencia, 'r'); // r == raiz
    saida();
}

void rotraiz(void) {
    float base, potencia;

    cout << endl;
    cout << "Operacao de radiciacao\n" << endl;
    cout << "Entre o valor da base: "; cin >> base;
    cin.ignore(80, '\n');
    cout << "Entre o valor do indice: "; cin >> potencia;
    cin.ignore(80, '\n');
    r = calculo(base, potencia, 'r'); // r == raiz
    saida();
}

int main(void) {
    cout << setprecision(2) << fixed << right;
    
    char opcao = ' ';
    float (*operacao)(float, float, char);

    do {
        cout << "Calculadora Simples" << endl;
        cout << string(80, '-') << endl;
        cout << "Escolha a operacao desejada:" << endl;
        cout << "Adicao         (+)" << endl;
        cout << "Subtracao      (-)" << endl;
        cout << "Multiplicacao  (*)" << endl;
        cout << "Divisao        (/)" << endl;
        cout << "Potenciacao    (^)" << endl;
        cout << "Radiciacao     (r)" << endl;
        cout << "Sair           (n)" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore(80, '\n');
        cout << endl;

        switch (opcao) {
            case '+' : rotadd(); break;
            case '-' : rotsub(); break;
            case '*' : rotmult(); break;
            case '/' : rotdiv(); break;
            case '^' : rotpotencia(); break;
            case 'r' : rotraiz(); break;
            case 'n' : cout << "Saindo da calculadora..." << endl; break;
            case 'N' : cout << "Saindo da calculadora..." << endl; break;
            default  : erro(1); break;
        }
    }while(opcao != 'n' and opcao != 'N');


    cout << endl;
    cout << "apertar <enter> para sair...";
    cin.get();
    return 0;
}