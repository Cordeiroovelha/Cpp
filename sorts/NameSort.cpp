// programa de ordenação de nomes

#include <iostream>
#include <string>
#include <array> 
using namespace std;

array<string, 10> str = {"Facebookson", "Walter", "Bruce Lee", "Reliquia", "Ana Cristina", "Anderlaine", "Bill Gates", "Joao", "Chuck Norris", "Zuleide"};

int main(void) {

    cout << "=== Desordenado ===" << endl;
    for (size_t i = 0; i < str.size(); i++) {
        cout << str[i] << endl;
    }

    for (size_t i = 0; i < str.size(); i++) {
        for (size_t j = 0; j < str.size(); j++) {
         if (str[i] < str[j]) {
            swap(str[i], str[j]);
         }
        }
    }
    
    cout << "================\n" << endl;

    cout << "=== Ordenado ===" << endl;
    for (size_t i = 0; i < str.size(); i++) {
        cout << str[i] << endl;
    }

    cout << "================" << endl;

    return 0;
}