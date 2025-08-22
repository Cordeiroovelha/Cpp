// volumecaixa.cpp

#include <iostream>
#include <print>

using namespace std;

int main(void){
	double volume, comprimento, largura, altura;
	
	println("Calculo de volume de uma caixa");
	println("..............................");
	cout << "Escreva o COMPRIMENTO da caixa:"; cin >> comprimento;
	cin.ignore(80, '\n');
	cout << "Escreva a LARGURA da caixa ...:"; cin >> largura;
	cin.ignore(80, '\n');
	cout << "Escreva a ALTURA da caixa ....:"; cin >> altura;
	cin.ignore(80, '\n');
	
	volume = altura * comprimento * largura;
	
	println("o volumer da caixa  ficou em .:{}",volume);	
	cout << endl;
	println("Aperte <enter> para continuar");
	cin.get();
	return 0;
}
