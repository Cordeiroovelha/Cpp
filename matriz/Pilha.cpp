#include <iostream>

const int MaxLeght = 4;
int pile[MaxLeght];
int top = 0;

void AddToPile(int value){
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
	
	top--; // não limpa, apenas esquece a localização do elemento
}

void ShowPile(){
	if(top == 0){
		std::cout << "Pilha vazia" << std::endl;
	}
	
	for(int i = top - 1; i >= 0; i--){
		std::cout << "|"<< pile[i] << "|" << std::endl;
		std::cout << "----" << std::endl;
	}
	
	std::cout << "\n------------" << std::endl;
}

int main(void){
	ShowPile();
	AddToPile(1);
	AddToPile(2);
	AddToPile(3);
	AddToPile(4);
	ShowPile();
	RemoveFromPile();
	RemoveFromPile();
	ShowPile();
	
}
