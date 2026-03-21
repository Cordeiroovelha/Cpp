// não consegui fazer

#include <iostream>
#include <array>
#include <string>

const int MaxLeght{5};
std::array<std::string, MaxLeght> pile;
int top = 0;

void AddToPile(std::string value){
    if(top == MaxLeght){
        std::cout << "Pilha cheia" << std::endl;
        return;
    }

    pile[top] = value;
    top++;
}

void RemoveFromPile(void){
    if(top == 0){
        std::cout << "Pilha vazia" << std::endl;
        return;
    }

    top--;
}

bool verify(std::string n){
    int control{0};
    for(int i{0}; i < n.length(); i++){
        if(n[i] == '(')
            control++;
        else if(n[i] == ')')
            control--;

        if(control < 0) {
            return false;
        }
    }

    return(control == 0);
}

void ShowPile(){
    if(top == 0){
        std::cout << "Pilha vazia" << std::endl;
    }
    std::cout << "------------" << std::endl;
    for(int i = top - 1; i >= 0; i--){
        std::cout << "|"<< pile[i] << "|" << std::endl;
        std::cout << "----" << std::endl;
    }

    std::cout << "------------\n" << std::endl;
}

int main(void){
    std::string enterance;
    bool confirm;

    std::cout << "Qual cadeia sera entrada? ";
    std::getline(std::cin, enterance);

    confirm = verify(enterance);

    if(confirm){
        AddToPile(enterance);
        std::cout << "Parenteses conferem" << std::endl;
    }else
        std::cout << "Parenteses NAO conferem" << std::endl;


    return 0;
}
