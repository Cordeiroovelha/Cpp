// volumecilindro.cpp

#include <iostream>
#include <cmath>
#include <print>

using namespace std;

int main(void){
	const double PI = 3.14159;
	double v, raio, altura;
	
	println("calculadora de volume de cilindros");
	println("..................................");
	println("");
	cout << "Digite o RAIO do cilindro:" << endl;
	cin >> raio;
	cin.ignore(80, '\n');
	cout << "Digite a ALTURA do cilindro" << endl;
	cin >> altura;
	cin.ignore(80, '\n');
	
	v = PI * pow(raio,2) * altura;
	
	println ("O volume do cilindro --> {}", v);
	cout << endl;
	cout <<"aperte <enter> para continuar";
	cin.get();
	return 0;
	}
