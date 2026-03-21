// Organização por seleção
// tempo de O(n²)

#include <iostream>
#include <algorithm>
using namespace std;
int arr[10] = {64,25,12,22,11,90,33,47,5,78};
int n = 10;
int cicles{0};


void SelectionSort(){
	int swaped{0};
	do{
		for(int i = 0; i < n - 1; i++){
			if(arr[i] > arr[i+1]){
				swap(arr[i], arr[i+1]);
				swaped = 0;
			}else
				++swaped;
			cicles++;
		}
	}while(swaped <= 10);
}

void DisplayArray(){
	for(int i = 0; i < n; i++){
		cout << arr[i] << '\t';
	}
}

int main(void){
	cout << "Desordenado: " << endl;
	DisplayArray();
	SelectionSort();
	cout << "\nOrdenado: " << endl;
	DisplayArray();
	cout << "\nQuantidade de buscas: " << cicles;
	return 0;
}
