#include <print>
#include <iostream>
#include <cstring>

int main(void){
    std::println("\n Aloc Dinamico");

    int* num = new int[5];

    for (int i = 0; i < 5; i++)
        num[i] = i* 2;
    
    std::print("Numeros: [");

    for (int i = 0; i < 5; i++){
        if (i < 4)
            std::print(" {} ,", num[i]);
        else
            std::println("{} ]", num[i]);
    }
    
    delete[] num;

    return 0;
}