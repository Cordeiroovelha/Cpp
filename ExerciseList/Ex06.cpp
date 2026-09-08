#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

int main(void){
    array<array<double, 2>, 4> arr01;
    array<array<double, 2>, 2> arr02;

    for(int i = 0; i < 2; i++){
        cout << "Aluno " << i+1 << endl;
        for(int j = 0; j < 4; j++){
            cin >> arr01[i][j];
            cin.ignore(80, '\n');
        }
    }

    double count{0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            count += arr01[i][j];
        }
        arr02[i][i] = count / 4;
    }
    
    cout << "=== Alunos e medias ===" << endl;
    for (int i = 0; i < 2; i++){
        cout << "Aluno " << i+1 << "Media: " << fixed << setprecision(2) << arr02[i][i];
        if(arr02[i][i] >= 7.0)
            cout << " situação: Aprovado " << endl;
        else
            cout << "situação: Reprovado " << endl;    
    }

    return 0;
}