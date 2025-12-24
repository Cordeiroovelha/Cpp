// passagem de parametro pro referencia 

#include <iostream>
using namespace std;

bool checkInt(int &value) {

    cin >> value;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    int A = 0;

    cout << "Type a number: ";
    if (!checkInt(A))
        cout << "invalid input!\n";
    else
        cout << "Your number is " << A << " ! " << endl;

    return 0;
}
