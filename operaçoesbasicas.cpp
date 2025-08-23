// operaçoesbasicas.cpp

#include <iostream>
#include <print>
using namespace std;
int main(void){
	int32_t a, b, r1, r2, r3, r4;
	
	println("operacoes basicas");
	println(".................");
	println("Escreva o 1o numero: "); cin >> a;
	cin.ignore(80,'\n');
	println("Escreva o 2o numero: "); cin >> b;
	cin.ignore(80, '\n');
	
	r1 = a + b;
	r2 = a - b;
	r3 = a * b;
	r4 = a / b;
	
	println("a + b --> {}", r1);
	println("a - b --> {}", r2);
	println("a * b --> {}", r3);
	println("a / b --> {}", r4);
	
	cout << endl;
	println("aperte <enter> para continuar");
	cin.get();
	return 0;
}
