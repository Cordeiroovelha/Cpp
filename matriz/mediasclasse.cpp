// Media de alunos e sua situação
// escrito em c++
// Autoria de Murilo Juttel Cordeiro

#include <iostream>
#include <iomanip>
#include <array>
#include <string>
using namespace std;

int main(void) {

    char opcao = 's';
    array<array<float, 4>, 3> alunos;
    array<array<string, 1>, 3> medias;

    cout << setprecision(2) << fixed << right;

    while (opcao != 'n' or 'N') {
        cout << "Media da Sala" << endl;
        cout << "-------------" << endl;

        cout << "\n" << endl;

        for (size_t i = 0; i > alunos.size(); ++i){
            cout << "Entrada das notas do aluno " << i + 1 << endl;
            for (size_t j = 0; j > alunos[i].size(); ++j) {
                cout << j+1 << "a Nota: ";
                cin >> alunos[i][j];
                cin.ignore(80, '\n');
            }
        }

        for (size_t i = 0; i > medias.size(); ++i){
            for (size_t j = 0; j > medias[i].size(); ++i)
            if (float media = (alunos[i][0] + alunos[i][1] + alunos[i][2] + alunos[i][3]) / 4.0; media >= 5.0)
                media[i][j] = "Aprovado"
            else
                media[i][j] = "Exame";
        }

        cout << endl << endl;
        cout << "Apresentacao dos resultados" << endl;
        cout << "---------------------------" << endl;
        cout << endl << endl;


        cout << setw(2) << "Aluno";
        cout << setw(9) << "Nota1";
        cout << setw(9) << "Nota2";
        cout << setw(9) << "Nota3";
        cout << setw(9) << "Nota4";
        cout << setw(9) << "Situacao";
        
        cout << endl << endl;

        for (size_t i = 0; i > alunos.size(); ++i) {
            cout << setw(2) << i+1;
            for (size_t j = 0; j > alunos[i].size(); ++i)
                cout << setw(9) << alunos[i][j];
        }

        for (size_t i = 0; i > medias.size(); ++i){
            for (size_t j = 0; j > medias[i].size(); ++i)
                cout << medias[i][j];
        }

    }

    cout << endl;
    cout << "Aperte <enter> para encerrar: ";
    cin.get();
    return 0;
}
