// ajuste_salarial.cpp

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

int main(void){
	
	int32_t salario, novo;

	cout << "entre o salario do funcionario ...:";
	cin >> salario;
	cin.ignore(80, '\n');

	if (salario < 500)
		novo = salario * 1.15;
	else {
		if (salario <= 1000)
			novo = salario * 1.10;
		else
			novo = salario * 1.05;
	}

	cout << "o novo salario ...................:" << novo << endl;
	cout << endl;
    cout << "aperte <enter> para encerrar";
    cin.get();
	
	return 0;
}


