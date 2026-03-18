#include <iostream>

int main(void){
    int notas[] = {6,5,7,8,9};

    for (int i = 0; i < 5; i++)
    {
        if (notas[i] > 7)
            std::cout << "Nota " << i << " = " << notas[i] << std::endl;
    }
    return 0; 
}
