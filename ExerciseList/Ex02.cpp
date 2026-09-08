#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<int> vec(10);

    for(int i = 0; i < vec.size(); i++){
        cin >> vec[i];
        cin.ignore(80, '\n');
    }

    cout << "\nOrdem inversa\n" << endl;

    for(int i = vec.size() - 1; i >= 0; i--)
        cout << vec[i] << endl;

    return 0;
}