// ------------------------------------------------------------
// informaçoes basicas sobre a sintaxe e estrutura de c++
// os exemplos que voce me enviou estão escritos com base no C
//  então sera o jeito que eu vou explicar
// ------------------------------------------------------------

#include <stdio.h>
#include <string>

// Para iniciar um programa é necessario a função "main"
// como escrito abaixo:

int main(void){

// --------------------------------------------------- //
// declaração de variavel:
// quando precisa usar algum dado como idade, nome, altura
// utiliza primeiramente o tipo do dado depois o nome do dado da seguinte maneira:
    int idade; // int = numero inteiro
    double altura; // double = numero com decimal
    char id; // char = caracter unico
    string nome; // string = palavra ou frase


// saida de dados:
// quando precisa ter alguma saida de qualquer informação
// se utiliza a função "printf" da seguinte maneira:
    printf("Hello World");

// entrada de dados:
// quando precisa que algo seja digitado,
// se utiliza a função "scanf" da seguinte maneira:
    scanf("%d", &idade); // %d = inteiro
    scanf("%lf", &altura); // %lf = double
    scanf("%c", &id); // %c = caracter
    scanf("%s", &nome); // %s = string

// --------------------------------------------------- //
// Decisão: if, else if, else
// Quando precisa tomar uma decisão se usa a estrutura "if"
// Quando voce precisa falar: "Se a primeira condição não for verdadeira" usa a estrutura "else"
// no seguinte exemplo, se a idade for maior ou igual a 18, printa na tela "Maior de idade"
    if (idade >= 18){
        printf("Maior de idade");
    }
    else { // se a idade for menor que 18, escreve "Menor de idade"
        printf("Menor de idade");
    }
// se precisar de mais de uma condição usa a estrutura "else if"
    if(idade >= 18){
        printf("Maior de idade");
    }
    else if(idade < 18 && idade >= 12){
        printf("Adolescente");
    }
    else {
        printf("Criança");
    }

 // --------------------------------------------------- //
// Loops / Laços: for, while
// Quando um comando precisa ser repetido varias vezes,
// não é preciso escrever varias vezes, apenas usando a estrutura de loops resolve
// O comando "While" é usado quando não se sabe quantas vezes o comando precisa ser repetido
// como no exemplo abaixo, enquanto a idade for menor que 18, printa na tela "Menor de idade"
    while( idade < 18) {
        scanf("%d", &idade);
        printf("Menor de idade");
        printf("Digite sua idade novamente");
    }

// Já o comando "for" é usado quando precisa repetir uma instrução um determinado numero de vezes,
// No exemplo, uma contagem de 0 a 10
for (int i = 0; i < 10; i++){ // i = a variavel de contagem, i < 10 é a condição de saida,
    printf("%d", i);          // i++ é o incremento a cada repetição do loop, nesse caso de 1 em 1
    printf("\n");
}


// para se encerrar o programa se utiliza a função "return 0" para informar que encerrou sem nenhum erro
    return 0;
}
