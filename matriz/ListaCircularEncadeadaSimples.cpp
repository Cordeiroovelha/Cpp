// Lista circular encadeada simples

#include <iostream>

struct knot
{
	int date;
	knot* next;
};


void InsertInEnd(knot*& head, int date){
	knot* newKnot = new knot{date, nullptr};
	
	if(head == nullptr)
		head = newKnot;
	else{
		knot* aux = head;
		while(aux->next != head)
			aux = aux->next;
		aux->next = newKnot;
	}
	newKnot->next = head;
}


void ViewArray(const knot* head){
	const knot* aux = head;
	do{
		std::cout << aux->date << "\t";
		aux = aux->next;
	}while(aux != head);
	std::cout << std::endl;
}

int main(void){
	knot* head = nullptr;
	int newValue;
	do{
		std::cin >> newValue;
		InsertInEnd(head, newValue);
		ViewArray(head);
	}while(newValue != -1);
	
	return 0;
}
