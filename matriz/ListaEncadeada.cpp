#include <iostream>

struct knot
{
	int date;
	knot* next;
};


void InsertInEnd(knot*& head, int date){
	knot* newKnot = new knot{date, nullptr}; // ponteiro contendo o novo dado
	if(head == nullptr) // verifica se esta nulo
		head = newKnot;
	else{
		knot* aux = head;
		while(aux->next != nullptr) // se não tiver, cria uma variavel aux
			aux = aux->next;        // Passa por todos até encontrar o elemento nulo(final da lista)
		aux->next = newKnot;        // Insere o dado no final
	}
}

void InsertInStart(knot*& head, int date){
	knot* newKnot = new knot{date, head}; // Cria um ponteiro com o novo dado no local da cabeça
	head = newKnot;						  // O novo elemento vai ser referido como a nova cabeça
}

void ViewArray(const knot* head){
	const knot* aux = head;
	while(aux != nullptr){
		std::cout << aux->date << "\t";
		aux = aux->next;
	}
	std::cout << std::endl;
}

int main(void){
	knot* head = nullptr;
	int newValue;
	do{
		std::cin >> newValue;
		//InsertInEnd(head, newValue);
		InsertInStart(head, newValue);
		ViewArray(head);
	}while(newValue != -1);
	
	while(head != nullptr) {
		knot* aux = head;
		head = head->next;
		delete aux;
	}
	
	return 0;
}
