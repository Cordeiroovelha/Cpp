// soma dos numeros 1 a 100

#include <iostream>
using namespace std;

int main(void) {
    uint32_t soma {0};

    for (uint32_t i = 1; i <= 100; i++) {
        soma += i;
    }

    // exemplo de laco while

    /*
        while (uint32_t = 1; i <= 100) {
            soma += i;
            i++;
        }  
    
    */

    
    // exemplo de laco until

    /*  
        uint32_t i = 1;
        do {
            soma += i;
            i++;
        } while (i <= 100);  
    
    */


    cout << "A soma dos numeros de 1 a 100 --> " << soma << endl;
    cout << endl;
    cout << "Aperte <enter> para encerrar o programa";
    cin.get();
    return 0;
}