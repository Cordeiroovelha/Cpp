// prestacaoV3.cpp
// auto: Murilo Juttel Cordeiro
// escrito em C++

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

int main(void){

    double valor, taxa, prestacao;
    int32_t tempo, tipo;
    char resp {'S'};
    cout << std::setprecision(2) << std::fixed << std::right;

    while (std::toupper(resp) == 'S'){

        cout << "**********************" << endl;
        cout << "* PRESTACAO ATRASADA *" << endl; // titulo
        cout << "**********************" << endl;
        cout << endl << endl;

        // entrada de dados com validaçao
      
        while (true) {
            cout << "Informe o valor inicial do produto (R$).......: ";
            if (cin >> valor)
                break;
            else{
                cout << "Erro: entre apenas valor numerico com dois decimais." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        cin.ignore(80, '\n');
        
        while (true) {
            cout << "Informe o valor da taxa (%) ..................: ";
            if (cin >> taxa)
                break;
            else{
                cout << "Erro: entre apenas valor numerico." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        cin.ignore(80, '\n');

        while (true) {
            cout << "Informe o valor da taxa (%) ..................: ";
            if (cin >> taxa)
                break;
            else{
                cout << "Erro: entre apenas valor numerico." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        cin.ignore(80, '\n');

        while (true) {
            cout << "Informe o tempo que esta atrasado (meses).....: ";
            if (cin >> tempo)
                break;
            else{
                cout << "Erro: entre apenas valor numerico." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        cin.ignore(80, '\n');

        cout << "Taxa simples [1] ou composta [2] .............: "; cin >> tipo;
        cin.ignore(80, '\n');
    
        taxa /= 100; // converte a taxa para porcentagem

        // apresentaçao dos resultados
        
        cout << endl << endl;
        cout << "**************" << endl;
        cout << "* RESULTADOS *" << endl;
        cout << "**************" << endl;
        cout << endl << endl;
        cout << "Valor inicial (R$)............................: " << setw(7) << valor << endl;
        cout << "Valor da taxa (%).............................: " << setw(7) << taxa * 100 << endl;
        cout << "Tempo de atraso (meses).......................: " << setw(4) << tempo << ".00"<< endl;

        // taxa simples ou composta e suas formulas

        if (tipo == 1){
            prestacao = valor + (1 + taxa * tempo);
		    cout << "Tipo de juros: Simples" <<  endl;
        }
        else {
            prestacao = valor * pow(1 + taxa, tempo);
            cout << "Tipo de juros: Composto" << endl;
        }
    
        double juros = prestacao - valor;

        cout << "Valor inicial (R$)............................: " << setw(7) << valor << endl;
        cout << "Juros por atraso (R$).........................: " << setw(7) << juros << endl;
        cout << "Valor total (R$)..............................: " << setw(7) << prestacao << endl;

        cout << "\n" << "\n" << endl;
        cout << "Deseja continuar? (S/N): ";
        cin.get(resp);
        cin.ignore();

		cout << "\n" << "\n" << endl;
    }

    cout << endl;
    cout << "Aperte <enter> para encerrar";
    cin.get();
    return 0;
}
