// A busca linear ela pode ser feita em listas não ordenadas
// seu tempo é O(n)

#include <iostream>
#include <array>
using namespace std;
int counter{0};
array<int, 10> arr = {3,7,12,18,25,31,44,56,70,88};

int search(int r){
	counter = 0;
	
	for(size_t i = 0; i < arr.size(); i++){
		if(arr[i] == r){
			counter++;
			return i + 1;
		}
		counter++;
	}
	return 0;
}

int main(void){
	
	int r;
	
	cout << "Qual elemento buscar: ";
	cin >> r;
	cin.ignore(80, '\n');
	int result = search(r);
	if (result){
		cout << "O elemento esta na posicao " << result << "\nQuantidade de buscas: " << counter << endl;
	}
	else{
		cout << "O elemento nao esta na lista" << "\nQuantidade de buscas: " << counter << endl;
	}
	return 0;
}

/*
quantidade de pesquisas
Valores | Ciclos:	
03 			 1
25 			 5
88 			 10
50 			 10
*/ 
