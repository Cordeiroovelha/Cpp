#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isVogal(char c){
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(void){
    string str;

    while(true){
        getline(cin,str);
        if(str.length() != 10)
            cout << "string muito comprida/curta" << endl;
        else
            break;
    }

    int consoante{0}, vogal{0};

    for (char c : str) {
        if (isalpha(c)) {
            if (isVogal(c))
                vogal++;
            else
                consoante++;
        }
    }
    
    cout << "str: " << str << endl;
    cout << "vogais: " << vogal << endl; 
    cout << "consoantes: " << consoante << endl;

    return 0;
}