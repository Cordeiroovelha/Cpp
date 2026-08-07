// programa de exemplo de looping

#include <stdio.h>
#include <chrono>
#include <thread>

int main(void) {
    int contador = 0;
    bool entradaValida = false;

    printf("Contador de numeros\n");

    while (entradaValida != true){
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &contador);

        if (contador < 0){
            printf("\nNumero invalido, digite novamente!\n");
        } else {
            entradaValida = true;
        }
    }

    printf("\nComecando a contagem:\n");
    
    for(int i = 0; i <= contador; i++){
        printf("%d\n", i);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    printf("\nContagem finalizada!\n");
    
    return 0;
}