// soma de duas matrizas de duas dimenção
// autoria de murilo juttel

#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

array<array<float, 3>, 5> A;
array<array<float, 3>, 5> B;
array<array<float, 3>, 5> C;


int main(void) {
    char opcao = 's';
    
    while (opcao != 'n' or 'N') {
        cout << "Soma de matriz" << endl;
        cout << "--------------" << endl;

        // entrada das duas matizes

        for (size_t i = 0; i < A.size(); i++) {
			cout << endl;
            cout << "linha " << i + 1 << endl;
            for (size_t j = 0; j < A[i].size(); j++) {
                cout << "Coluna " << j+1 << " valor: ";
                cin >> A[i][j];
                cin.ignore(80, '\n');
            }
        }

        for (size_t i = 0; i < B.size(); i++) {
			cout << endl;
            cout << "linha " << i + 1 << endl;
            for (size_t j = 0; j < B[i].size(); j++) {
                cout << "Coluna " << j+1 << " valor: ";
                cin >> B[i][j];
                cin.ignore(80, '\n');
            }
        }

        // criação da matriz c

        for (size_t i = 0; i < C.size(); i++) {
            for (size_t j = 0; j < C.size(); j++) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }


        // apresentação dos resultados

        cout << "Resultado da soma dos elementos" << endl << endl;

        for (size_t i = 0; i < C.size(); i++) {
            cout << "Linha " << i + 1 << endl;
            for (size_t j = 0; j < C.size(); j++) {
                cout << "Coluna " << j+1 << " valor: " << C[i][j] << endl;
            }
        }

        // opção de continuação

        cout << "\n" << "\n";
        cout << "Deseja realizar outra soma? (s/n): ";
        cin.get(opcao);
        cin.ignore(80, '\n');
    }

    cout << endl;
    cout << "aperte <enter> para encerrar";
    cin.get();
    return 0;
}
