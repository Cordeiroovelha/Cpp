#include <iostream>
using namespace std;

void Swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int Partition (int arr[], int low, int high){
	int pivot = arr[high];
	int i = (low - 1);
	for(int j = low; j <= high - 1; j++){
		if (arr[j] <= pivot){
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void QuickSort(int arr[], int low, int high){
	if (low < high){
		int pivot = Partition(arr, low, high);
		
		QuickSort(arr, low, pivot - 1); 
		QuickSort(arr, pivot + 1, high);
	}
}


void DisplayArray(int arr[], int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << '\t';
	}
}


int main(void){
	int arr[] = {9,8,5,6,7,4,2,1,3,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Desordenada" << endl;
	DisplayArray(arr, n);
	cout << "\nOrdenada" << endl;
	QuickSort(arr, 0, n-1);
	DisplayArray(arr, n);
	cout << endl;
	return 0;
	
}
