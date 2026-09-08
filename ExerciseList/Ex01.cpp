#include <iostream>
#include <array>
using namespace std;

int main(void){
    array<int, 10> arr;

    for (int i = 0; i < arr.size(); i++){
        cin >> arr[i];
        cin.ignore(80, '\n');
    }

    cout << "\nElementos\n";

    for(int i : arr)
        cout << i << endl;

    return 0;
}