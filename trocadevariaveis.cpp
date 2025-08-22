// trocadevariaveis.cpp

#include <iostream>
using namespace std;

int main(void){
	int32_t a, b, r;
	cout << "Troca de Variaveis" << endl;
	cout << ".................." << endl;
	cout << "Escreva a variavel A: "; cin >> a;
	cin.ignore(80, '\n');
	cout << "Escreva a variavel B: "; cin >> b;
	
	r = a;
	a = b;
	b = r;
	
	cout << "Variavel A --> " << a << endl;
	cout << "Variavel B --> " << b << endl;
	
	cout << endl;
	cout << "aperte <enter> para continuar";
	cin.get();
	return 0;
}
