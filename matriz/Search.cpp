#include <iostream>
using namespace std;

int search(int arr[], int r){
	for(int i = 0; i < 5; i++){
		if(arr[i] == r){
			return i + 1;
		}
	}
	return 0;
}

int main(void){
	int arr[] = {1,3,5,7,9};
	int r;
	
	cout << "Qual elemento buscar: ";
	cin >> r;
	cin.ignore(80, '\n');
	int result = search(arr, r);
	if (result)
		cout << "O elemento esta na posicao " << result;
	else
		cout << "O elemento nao esta na lista" << endl;
	
	return 0;
}
