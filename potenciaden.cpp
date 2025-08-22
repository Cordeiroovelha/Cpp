// potenciaden.cpp

#include <iostream>
#include <cmath>
#include <print>

using namespace std;

int main(void){
	float b, e, r;
	println("Calculadora de exponente");
	println("........................");
	cout << endl;
	println("escreva a base: "); cin >> b;
	cin.ignore(80, '\n');
	println("escreva o expoente:"); cin >> e;
	cin.ignore(80, '\n');
	
	r = pow(b,e);
	
	println("o resultado da operacao : {}", r);
	cout << endl;
	cout << "aperte <enter> para continuar";
	cin.get();
	return 0;
}
