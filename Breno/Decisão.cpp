// programa de exemplo de decisão

#include <stdio.h>

int main(void){
    int idade;

    printf("=================\n");
    printf("Entrada da balada\n");
    printf("=================\n");
    printf("\nDigite sua idade: ");
    scanf("%d", &idade);

    if (idade >= 18){
        printf("\nEntrada Liberada!\n");
    } else if (idade < 18 && idade >= 16){
        printf("\nSo com autorizacao dos pais :(\n");
    } else {
        printf("\nSai daqui moleque!\n");
    }

    return 0;
}