#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

int main(void){
    array<double, 15> arr;

    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
        cin.ignore(80, '\n');
    }

    cout << "\nMedia\n" << endl;

    double R = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        R += arr[i];
    }
    
    R /= arr.size();

    cout << fixed << setprecision(2) << R << endl;

    return 0;
}