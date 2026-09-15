#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main(void){
    string str;
    int count{0};

    getline(cin, str);

    for(char c : str){
        if(isalpha(c)){
            count++;
        }
    }

    cout << "Letras na string: " << count << endl;
    return 0;
}