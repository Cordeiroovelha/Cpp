// programa que faz a entrada e validação de notas de um restaurante
// autoria de Murilo Juttel Cordeiro
// escrito em c++

#include <iostream>
#include <iomanip>
#include <vector>
#include <print>
using namespace std;

class Cliente {
    private:
        uint64_t mesa;
        vector<int32_t> menu;
        float total;
    public:
        Cliente : menu(4) {}
        Cliente(uint64_t mesa, int32_t menu, float total) 
        : mesa(mesa), menu(menu), total(total) {}

        void Saida(void){
            for (size_t i = 0; i <= menu.size; i++)
        }
    
        ~Cliente() {}
};