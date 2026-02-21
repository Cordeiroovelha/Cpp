#include <iostream>
using namespace std;

struct knot
{
	int date;
	knot* next;
};


void Insert(knot*& head, int date){
	knot* newKnot = new knot{date, nullptr};
	if(head == nullptr)
		head = newKnot;
	else{
		knot* aux = head;
		while(aux->next != nullptr)
			aux = aux->next;
		aux->next = newKnot;
	}
}

void ViewArray(const knot* head){
	const knot* aux = head;
	while(aux != nullptr){
		cout << aux->date << "\t";
		aux = aux->next;
	}
	cout << endl;
}

int main(void){
	knot* head = nullptr;
	int newValue;
	do{
		cin >> newValue;
		Insert(head, newValue);
		ViewArray(head);
	}while(newValue != -1);
	
	return 0;
}
