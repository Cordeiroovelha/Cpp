#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main(void){
    array<int, 20> arr01;
    vector<int> pares;
    vector<int> impares;

    for(int i = 0; i < arr01.size(); i++){
        cin >> arr01[i];
        cin.ignore(80, '\n');
    }

    for(int i = 0; i < arr01.size(); i++){
        if (arr01[i] % 2 == 0)
            pares.push_back(arr01[i]);
        else
            impares.push_back(arr01[i]);
    }

    cout << "Array: ";
    for(int i : arr01)
        cout << i << " , ";

    cout << "\nPares: ";
    for(int i : pares)
        cout << i << " , ";

    cout << "\nImpares: ";
    for(int i : impares)
        cout << i << " , ";


    return 0;
}