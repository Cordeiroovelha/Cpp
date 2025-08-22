// somadepotencia.cpp

#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int32_t a, b, c, r;
	
	cout << "Somatoria da potencia de 3 numeros" << endl;
	cout << "..................................";
	cout << endl;
	cout << "escreva o 1o numero .............:";
	cin >> a;
	cin	.ignore(80,'\n');
	cout << "escreva o 2o numero .............:";
	cin >> b;
	cin.ignore(80, '\n');
	cout << "escreva o 3o numero .............:";
	cin >> c;
	cin.ignore(80, '\n');
	
	r = pow(a,2) + pow(b,2) + pow(c,2);
	
	cout << "o resultado da operacao .........:" << r << endl;
	cout << endl;
	cout << "aperte <enter> para continuar";
	cin.get();
	
	return 0;
}
