#include <iostream>
#include <string>
#include <print>
using namespace std;

void print01(int num[], size_t lenght, string name);
void print02(int *num, size_t lenght, string name);
void sing(int);
void dance(int);
void role(int);

int main(void){

    println("\nRelacionamento entre Array e Ponteiro\n");

    int num01[] = {1,2,3,4,5};
    int num02[] = {6,7,8,9,10};
    int num03[] = {11,12,13,14,15};
    
    size_t lenght01 = sizeof(num01)/ sizeof(num01[0]);
    size_t lenght02 = sizeof(num02)/ sizeof(num02[0]);
    size_t lenght03 = sizeof(num03)/ sizeof(num03[0]);
    
    print01(num01, lenght01, "<numeros1>");
    print02(num02, lenght02, "<numeros2>");
    
    int *ptr03 = num03;

    print("3. <*ptr03>...: [");

    for (int i = 0; i < lenght03; i++) {
        if (i < lenght03 - 1)
            cout << ptr03[i] << ", ";
        else
            cout << ptr03[i] << "]\n";
    }
    
    println("\nArray de Ponteiro para funções\n");
    void (*function[3])(int) = {
        sing,
        dance,
        role
    };

    int opt;
    while ((opt >= 0) && (opt < 3)) {
    
        (*function[opt])(opt);

        print(">> Informe a opcao desejada (0,1,2): ");
        cin >> opt;
        cin.ignore(80, '\n');

    }
    


    return 0;
}

void print01(int num[], size_t lenght, string name) {
    println("1. {} : [", name);

    for (int i = 0; i < lenght; i++) {
        if (i < lenght - 1)
            cout << num[i] << ", ";
        else
            cout << num[i] << "]\n";
    }
}

void print02(int *num, size_t lenght, string name) {
    println("1. {} : [", name);

    for (int i = 0; i < lenght; i++) {
        if (i < lenght - 1)
            cout << *(num + 1) << ", ";
        else
            cout << *(num + 1) << "]\n";
    }
}