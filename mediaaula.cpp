// mediaaula.cpp

#include <iostream>
using namespace std;

int main(void){
    int32_t n1, n2, n3, n4;

    cout << "nota da 1a prova --> "; cin >> n1;
    cin.ignore(80, '\n');
    cout << "nota da 2a prova --> "; cin >> n2;
    cin.ignore(80, '\n');
    cout << "nota da 3a prova --> "; cin >> n3;
    cin.ignore(80, '\n');
    cout << "nota da 4a prova --> "; cin >> n4;
    cin.ignore(80, '\n');

    if (double r = (n1 + n2 + n3 + n4) / 4; r > 5)
        cout << "Aprovado, media --> " << r;
    else
        cout << "Reprovado, media --> " << r;

    cout << endl;
    cout << "aperter <enter> para continuar";
    cin.get();
    return 0;
}
