// sub-rotina associada a ponteiros

#include <iostream>
using namespace std;

int Soma(int x, int y) {
    return x + y;
}

int Subtracao(int x, int y) {
    return x - y;
}


int main(void) {
    int32_t (*funcaoPont)(int32_t, int32_t);
    int32_t resultado, A, B;;

    funcaoPont = Soma; // ou  funcaoPont = &Soma;
    cin >> A;
    cin.ignore(80, '\n');
    cin >> B;
    cin.ignore(80, '\n');
    resultado = funcaoPont(A, B);
    cout << "Resultado da soma: " << resultado << endl;
    funcaoPont = Subtracao; // ou  funcaoPont = &Subtracao;
    resultado = funcaoPont(A, B);
    cout << "Resultado da subtracao: " << resultado << endl;

    cout << endl;
    cout << "Aperte <enter> para continuar...";
    cin.get();
    return 0;
}