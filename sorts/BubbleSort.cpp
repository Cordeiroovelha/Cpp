#include <iostream>
#include <algorithm>
using namespace std;

void BubbleSort(int arr[], int n){
	bool Swapped;
	for(int i = 0; i < n - 1; i++){
		Swapped = 0;
		for(int j = 0; j < n-1; j++){
			if (arr[j] < arr[j - 1]){
				swap(arr[j], arr[j - 1]);
				Swapped = true;
			}
		}
		if (!Swapped)
			break;
	}
}

void printArray(int arr[], int n){
	for(int i = 0; i < n - 1; i++){
		cout << arr[i] << " | ";
	}
}

int main(void){
	int n = 10;	
	int arr[] = {8,6,5,9,7,4,3,2,1};
	
	printArray(arr, n);
	cout << endl << endl;
	BubbleSort(arr, n);
	printArray(arr, n);
	
	return 0;
}
