#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<int> A(10); vector<int> B(10);
    vector<int> C(A.size() + B.size());

    cout << "Vector A:\n";
    for (size_t i = 0; i < A.size(); i++)
        cin >> A[i];
    
    cout << "\nVector B:\n";
    for (size_t i = 0; i < B.size(); i++)
        cin >> B[i];

    size_t j{0};
    for (size_t i = 0; i <= B.size(); i++) {
        C[j] = A[i];
        ++j;
        C[j] = B[i];
        ++j;
    }

    cout << "\nVector C:\n";

    for(size_t i = 0; i < C.size(); i++){
        cout << C[i] << endl;
    }


    return 0;
}