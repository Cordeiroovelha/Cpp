#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
    int AddTotal{0}, AddSquare{0};
    vector<int> vec(10);
    
    for (size_t i = 0; i < vec.size(); i++)
        cin >> vec[i];
    
    for(int i : vec){
        cout << "\n" << i << " square root = " << pow(i, 2);
        AddTotal += i;
        AddSquare += pow(i, 2);
    }
    cout << "\nSoma do total: " << AddTotal;
    cout << "\nSoma dos Quadrados: " << AddSquare;

    return 0;
}