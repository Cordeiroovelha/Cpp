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
        while(aux->next != nullptr)
            aux = aux->next;
        aux->next = newKnot;
    }
}

void InsertInStart(knot*& head, int date){
    knot* newKnot = new knot{date, head};
    head = newKnot;
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
        knot* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
