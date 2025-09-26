// prestacaoatrasada.cpp

#include <iostream>
#include <cmath>
#include <print>
using namespace std;

int main(void){
	float valor, taxa, tempo, prestacao;
	
	println("Calculadora de prestacao atrasada");
	println(".................................");
	cout << endl;
	println("Escreva o valor do produto"); cin >> valor;
	cin.ignore(80, '\n');
	println("Escreva o valor da taxa"); cin >> taxa;
	cin.ignore(80, '\n');
	println("Escreva quanto tempo esta atrasado"); cin >> tempo;
	cin.ignore(80, '\n');
	prestacao = valor + (valor * (taxa/100)*tempo);
	println("O valor da prestacao ........: {}", prestacao);
	
	cout << endl;
	cout << "Aperte <enter> para continuar";
	cin.get();
	return 0;
}
