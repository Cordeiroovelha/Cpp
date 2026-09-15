#include <iostream>
#include <array>
using namespace std;

int main(void) {
    array<int, 5> arr;
    int add{0}, mult{1};

    for(size_t i = 0; i < arr.size(); i++){
        cin >> arr[i];
        cin.ignore(80, '\n');
    }
    
    for(size_t i = 0; i < arr.size(); i++){
        add += arr[i];
    }

    for(size_t i = 0; i < arr.size(); i++){
        mult *= arr[i];
    }

    cout << "Adição dos numeros: " << add << endl;
    cout << "Multiplicação dos numeros: " << mult << endl;


    return 0;
}