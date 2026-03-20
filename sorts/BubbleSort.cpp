// BubbleSort é um organizador de dados que compara o elemento atual com o proximo
// seu tempo é O(n²)

#include <iostream>

const int MaxLeght = 10;
int arr[MaxLeght] = {64,25,12,22,11,90,33,47,5,78};
int cicles{0};

void bubbleSort(){
	bool swaped;
	
	for (int i = 0; i < MaxLeght - 1; i++){
		swaped = false;
		for(int j{0}; j < MaxLeght - i - 1 ; j++){
			if(arr[j] > arr[j + 1]){
				std::swap(arr[j], arr[j + 1]);
				swaped = true;
			}
			cicles++;
		}
		if(!swaped) break;
	}
}

void DisplayArray(){
	for(int i = 0; i < MaxLeght; i++){
		std::cout << '|' << arr[i] << '|' << '\t';
	}
}

int main(void){
	std::cout << "Desordenado: " << std::endl;
	DisplayArray();
	bubbleSort();
	std::cout << "\nOrdenado: " << std::endl;
	DisplayArray();
	std::cout << "\nQuantidade de buscas: " << cicles;
    return 0; 
}

// tempo: 0.0124
