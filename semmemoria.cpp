// semmemoria.cpp

#include <iostream>
#include <cmath>
#include <print>
using namespace std;

int main(void){
	int32_t a, b;
	
	println("calculadora sem armazenamento na memoria");
	println("........................................");
	cout << "Escolha um valor A: "; cin >> a;
	cin.ignore(80, '\n');
	cout << "Escolha um valor B: "; cin >> b;
	cin.ignore(80, '\n');
	cout << endl;
	
	cout << "A + B --> " << a + b << endl;
	cout << endl;
	println("A - B --> {}\n", a - b);
	println("A * B --> {}\n", a * b);
	cout << "A / B --> " << a / b << endl;
	cout << endl;
	
	cout << endl;
	cout << "aperte <enter> para continuar";
	cin.get();
	return 0;
}
