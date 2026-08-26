#include <print>
#include <iostream>
#include <cstring>

int main(void){

    std::println("\nExemplo de uso da função strcmp()\n");

    const char *names[] = {
        "Paul",
        "Pokemon",
        "Unc",
        "Algusto",
        "Mineiro",
        "Brasil"
    };

    size_t total = sizeof(names) / sizeof(names[0]);

    const char *temp;
    int i, j;

    std::println(">> Total de nomes: {}\n", total);

    std::println("* Antes de ordenacao: \n");
    for (i = 0; i < total; i++)
        std::println("{}. {}", i+1, names[i]);
    
    for (i = 0; i < total - 1; i++) {
        for (j = i + 1; j < total; j++) {
            if(std::strcmp(names[i], names[j]) > 0)
                std::swap(names[i], names[j]);    
        }
    }

    std::println("\n* Depois de ordenacao: \n");
    for (i = 0; i < total; i++)
        std::println("{}. {}", i+1, names[i]);
    
    return 0;
}