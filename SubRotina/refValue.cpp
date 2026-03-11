// ref value é um valor que é passado por referência, ou seja, ele é um alias para o valor original. 
//Ele é criado usando o operador && e pode ser usado para otimizar o desempenho de funções que recebem 
// objetos grandes como parâmetros, evitando a cópia desnecessária desses objetos.

#include <iostream>

void printTest(int &&){
    std::cout << "printTest(int &&)" << std::endl;
}

int main()
{
    int x{10};
    
    printTest(5);
    
    return 0;
}
