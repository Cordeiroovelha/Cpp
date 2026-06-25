#include <iostream>
#include <string>
#include <sstream>
using namespace std;

double calculator(string expression){
    stringstream buffer(expression);
    double num1, num2;
    char opr;

    buffer >> num1 >> opr >> num2;

    if(buffer.fail()){
        cout << "Formato invalido" << endl;
        buffer.clear();
        buffer.str("");
        return 0;
    }

    switch (opr){
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return num1 / num2;
    case '^': return pow(num1,num2);
    case 'r': return pow(num1, 1.00 / num2);
    default : return 0.0;
    }
}

int main(void){
    int opt{0};
    string operacao;

    while(opt != 2){
        cout << "-------------" << endl;
        cout << " CALCULADORA " << endl;
        cout << "-------------" << endl;
        cout << "\n" << endl;
        cout << "Formatacao (X + Y)" << endl;
        cout << "Operacao: ";
        getline(cin, operacao);

        try{
            double r = calculator(operacao);
            cout << operacao << " = " << r << endl;
        } catch(const exception& e){
            cout << "Erro: " << e.what() << endl;
        }

        cout << "Continuar? (aperte 2 para nao) ";
        cin >> opt;
        cin.ignore(80, '\n');
    }
}