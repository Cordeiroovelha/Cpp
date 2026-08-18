// exemplo de programa apenas com entrada e saida

#include <stdio.h>

int main(void) {
    int numInt;
    float numFloat;
    char nome[20];

    printf("Digite um numero inteiro: ");
    scanf("%d", &numInt);

    printf("Digite um numero float: ");
    scanf("%f", &numFloat);

    printf("Digite um nome: ");
    scanf("%s", &nome);

    printf("\n");
    printf("===============================\n");
    printf("\n");
    
    printf("O numero inteiro digitado foi: %d\n", numInt);
    printf("O numero float digitado foi: %f\n", numFloat);
    printf("O nome digitado foi: %s\n", nome);
    
    return 0;
}