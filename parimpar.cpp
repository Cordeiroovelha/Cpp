// Par e impar 
// decisão composta

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main(void) {
    
    int32_t n;
    
    cout << "Digite um numero: "; cin >> n;
    cin.ignore(80, '\n');
    
    if (int32_t r = n % 2; r == 0)
        cout << n << " e par." << endl;
    else
        cout << n << " e impar." << endl;

    cout << "Aperte <enter> para encerrar ";
    cin.get();
    return 0;
}

