// mediaaula2.cpp

#include <iostream>
using namespace std;

int main(void){
    int32_t n1, n2, n3, n4;
    double ne;

    cout << "nota da 1a prova --> "; cin >> n1;
    cin.ignore(80, '\n');
    cout << "nota da 2a prova --> "; cin >> n2;
    cin.ignore(80, '\n');
    cout << "nota da 3a prova --> "; cin >> n3;
    cin.ignore(80, '\n');
    cout << "nota da 4a prova --> "; cin >> n4;
    cin.ignore(80, '\n');

    double nd1 = (n1 + n2 + n3 + n4) / 4.0;
    
    if (nd1 < 7){
        cout << "media alcancada insuficiente, digite a nota do exame: "; cin >> ne;
        cin.ignore(80, '\n');
        double nd2 = (nd1 + ne) / 2.0;
        if (nd2 >= 5)
            cout << "aprovado por exame, media --> " << nd2;
        else
            cout << "reprovado, media --> " << nd2; 
    }
    else
        cout << "aprovado, media --> " << nd1;

    cout << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
    return 0;
}
