// Media de alunos e sua situação
// escrito em c++
// Autoria de Murilo Juttel Cordeiro

#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

struct CadAluno {
    string nome;
    array<float, 4> notas;
    string situacao;
}

bool CompNome(const CadAluno &a, const CadAluno &b) 
{
  return a.nome < b.nome;
}

union SalaSize {
    uint32_t sala30 = 30;
    uint32_t sala15 = 15;
}

void clear(void) {
    HANDLE tela;
    CONSOLE_SCREEN_BUFFER_INFO info;
    DWORD escrita = 0;
    tela = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(tela, &info);
    COORD pos = {0, 0};
    DWORD celulas = info.dwSize.X * info.dwSize.Y;
    FillConsoleOutputCharacter(tela, ' ', celulas, pos,
    &escrita);
    SetConsoleCursorPosition(tela, pos);
}

int main(void) {

    vector<CadAluno> Alunos(salaSize);

    char opcao = 's';
    uint32_t Sala;

    cout << setprecision(2) << fixed << right;

    while (opcao != 'n' or 'N') {
        cout << "Media da Sala" << endl;
        cout << string(80, '-') << endl;

        cout << endl << endl;

        cout << "Quantos alunos possue a classe (15 ou 30)? ";
        cin >> Sala;
        cin.ignore(80, '\n');

        if (Sala == 15)
            Alunos.resize(SalaSize.sala15);
        else if (Sala == 30)
            Alunos.resize(SalaSize.sala30);
        else {
            cout << "Valor invalido, sera usado o padrao 30 alunos" << endl;
            cout << endl;
            Alunos.resize(sala30);
        }
        cout << endl;

        for (size_t i = 0; i < Alunos.size(); ++i){
            cout << "Nome do aluno: ";
            getline(cin, Alunos[i].Nome);
            cout << "Entrada das notas do aluno " << Alunos[i].Nome << endl;
            cout << endl;
            for (size_t j = 0; j < Alunos[i].size(); j++) {
                if (j < 4){
                    cout << "Prova " << j+1 << " : ";
                    cin >> Alunos[i].Notas[j];
                    cin.ignore(80, '\n');
                }
                else{
                    cout << "Prova final: ";
                    cin >> Alunos[i].Notas[j];
                    cin.ignore(80, '\n');
                }
            }
            cout << endl;
        }

        sort(alunos.begin(), alunos.end(), cmpNome)


        // entrada de dados
        for (size_t i = 0; i < alunos.size(); ++i){
            cout << "Entrada das notas do aluno " << i + 1 << endl;
            cout << endl;
            for (size_t j = 0; j < alunos[i].size(); ++j) {
                cout << j+1 << "a Nota: ";
                cin >> alunos[i][j];
                cin.ignore(80, '\n');
            }
            cout << endl;
        }

        for (size_t i = 0; i < medias.size(); ++i){
            if (float media = (alunos[i][0] + alunos[i][1] + alunos[i][2] + alunos[i][3]) / 4.0; media >= 5.0)
                medias[i] = "Aprovado";
            else
                medias[i] = "Reprovado";
        }

        cout << endl << endl;
        cout << "Apresentacao dos resultados" << endl;
        cout << "---------------------------" << endl;
        cout << endl << endl;


        cout << setw(6)  << "Aluno";
        cout << setw(8)  << "Nota1";
        cout << setw(9)  << "Nota2";
        cout << setw(9)  << "Nota3";
        cout << setw(9)  << "Nota4";
        cout << setw(12) << "Situacao";
        
        cout << endl;

        cout << string(80, '-') << endl;

        for (size_t i = 0; i < alunos.size(); ++i) {
            cout << setw(4) << i+1;
            for (size_t j = 0; j < alunos[i].size(); ++j)
                cout << setw(9) << fixed << setprecision(1) << alunos[i][j];  

            cout << setw(13) << medias[i];
            cout << endl;
        }

        cout << endl << endl;
        cout << "Deseja calcular outra classe? ";
        cin.get(opcao);
        cin.ignore(80, '\n');
        if (opcao == 's' or 'S')
            clear();
    }

    cout << endl;
    cout << "Aperte <enter> para encerrar: ";
    cin.get();
    return 0;
}
