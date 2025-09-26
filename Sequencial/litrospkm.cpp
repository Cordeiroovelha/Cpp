// litorsporkm.cpp

#include <iostream>
#include <print>
using namespace std;

int main(void){
	double litros, distancia, tempo, velocidade;
	
	println("Calculadora de litros utlizados (12km por litro)");
	println("................................................");
	cout << endl;
	cout << "Digite o TEMPO da viagem : "; cin >> tempo;
	cin.ignore(80, '\n');
	cout << "Digite a Velocidade media:"; cin >> velocidade;
	cin.ignore(80, '\n');
	
	distancia = velocidade * tempo;
	litros = distancia/12;
	
	cout << endl;
	println("...............................................");
	cout << endl;
	
	println("a velocidade media ficou em: {} km/h", velocidade);
	println("o tempo gasto ficou em ....: {} horas", tempo);
	println("a distancia percorida foi .: {} km", distancia);
	println("os litros gastos foram ....: {:.2f} litros", litros);
	
	cout << endl;
	println("aperte <enter> para continuar");
	cin.get();
	return 0;
}
