// bhaskara.cpp

#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    float a, b, c;
    
    cout << "ecolha um valor <A>: "; cin >> a;
    cin.ignore(80, '\n');
    cout << "ecolha um valor <B>: "; cin >> b;
    cin.ignore(80, '\n');
    cout << "ecolha um valor <C>: "; cin >> c;
    cin.ignore(80, '\n');
    
    if (a != 0){
        double delta = pow(b,2) - (4.0 * a * c);
        if (delta < 0)
            cout << "nao existe solucao real --> delta < 0";
        else{
            float r1 = ((-1*b) + sqrt(delta)) / (2 * a);
            float r2 = ((-1*b) - sqrt(delta)) / (2 * a);
            cout << "r1 --> " << r1 << endl;
            cout << "r2 --> " << r2 << endl;
        }
    }
    else
        cout << "quando a = 0 a equacao e de primeiro grau";

    cout << endl;
    cout << "aperte <enter> para continuar";
    cin.get();
    return 0;
}
