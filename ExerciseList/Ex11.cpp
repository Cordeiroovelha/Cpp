#include <iostream>
#include <vector>
using namespace std;

struct Aluno{
    int idade;
    float altura;
};

int main(void){
    vector<Aluno> classe01(4);
    vector<Aluno> classe02(4);
    vector<Aluno> classe03(4);
    vector<Aluno> classe04(4);
    int mediaAltura;

    cout << "Sala 1" << endl;
    for (size_t i = 0; i < classe01.size(); i++) {
        cout << "Aluno" << i+1 << " Idade: ";
        cin >> classe01[i].idade;
        cout << "Altura: ";
        cin >> classe01[i].altura;
    }
    
    cout << "Sala 2" << endl;
    for (size_t i = 0; i < classe01.size(); i++) {
        cout << "Aluno" << i+1 << " Idade: ";
        cin >> classe02[i].idade;
        cout << "Altura: ";
        cin >> classe02[i].altura;
    }

    cout << "Sala 3" << endl;
    for (size_t i = 0; i < classe01.size(); i++) {
        cout << "Aluno" << i+1 << " Idade: ";
        cin >> classe03[i].idade;
        cout << "Altura: ";
        cin >> classe03[i].altura;
    }

    cout << "Sala 4" << endl;
    for (size_t i = 0; i < classe01.size(); i++) {
        cout << "Aluno" << i+1 << " Idade: ";
        cin >> classe04[i].idade;
        cout << "Altura: ";
        cin >> classe04[i].altura;
    }

    for (size_t i = 1; i < 4; i++) {
        mediaAltura += classe01[i].altura;
        
    }
    

    return 0;
}