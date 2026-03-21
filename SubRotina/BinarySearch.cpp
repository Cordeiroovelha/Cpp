// A busca binaria só pode ser utilizada para buscas em listas ordenadas
// Possue um tempo de O(log n)

#include <iostream>
#include <array>
using namespace std;
int cicles{0};
int binarySearch(int arr[], int r){
	int start{0};
	int end{10 - 1};
	
	do{
		int half = (start + end) / 2;
		if (arr[half] == r){
			cicles++;
			return half + 1;
		} else if(arr[half] < r)
			start = half +1;
		else
			end = half -1;
		cicles++;
	}while(start <= end);
	return (-1);
}

int main(void){
	int arr[10] = {3,7,12,18,25,31,44,56,70,88};
	int r;
	
	cout << "Qual elemento buscar: ";
	cin >> r;
	cin.ignore(80, '\n');
	int result = binarySearch(arr, r);
	if (result != -1){
		cout << "O elemento esta na posicao " << result << "\nQuantidade de buscas: " << cicles << endl;
	}
	else{
		cout << "O elemento nao esta na lista" << "\nQuantidade de buscas: " << cicles << endl;
	}	
	return 0; 
}

/*
	quantidade de pesquisas
	Valores	| Ciclos	
	03 			 3
	25 			 1
	88 			 4
	50 			 4
*/ 
