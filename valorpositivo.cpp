// valorpositivo.cpp

#include <iostream>
using namespace std;

int main(void){
    int32_t n;

    cout << "Escolha um valor <N>: "; cin >> n;
    cin.ignore(80, '\n');

    if (n < 0)
        cout << "o valor na sua forma positiva --> " << -1 * n;
    else
        cout << "o valor na sua forma positiva --> " << n;
    
    cout << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
    return 0;
}
