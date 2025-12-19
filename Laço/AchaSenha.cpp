#include <iostream>
using namespace std;

int main(void) {
    const string Pass("HER");

    for (char a = 'A'; a <= 'Z'; ++a){

        for (char b = 'A'; b <= 'Z'; ++b){

            for (char c = 'A'; c <= 'Z'; ++c){

                const string tempPass({a, b, c});
                cout << tempPass << endl;
                if (tempPass == Pass){
                    cout << "Password found: " << tempPass << endl;
                    goto END;
                }
            }
        }
    }
END:

    return 0;
}

