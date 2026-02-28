#include <iostream>

/*
	Crie uma fila dinamica usando lista encadeada em C++
*/


const int MaxLeght = 4;
int line[MaxLeght];
int start = 0, end = 0;
bool EmptyLine = true;

void AddToLine(int value){
	if (end == start && !EmptyLine){
		std::cout << "Fila cheia" << std::endl;
		return;
	}
	
	line[end] = value;
	EmptyLine = false;
	end++;
	if (end == MaxLeght){
		end = 0;
	}
}

void RemoveFromLine(void){
	if (EmptyLine){
		std::cout << "Fila Vazia" << std::endl;
		return;
	}
	
	start++;
	if(start == MaxLeght){
		start = 0;
	}
	if(start == end && !EmptyLine){
		EmptyLine = true;
	}
}

void ShowLine(void){
	if(EmptyLine){
		std::cout << "Fila vazia" << std::endl;
		return;
	}
	
	if(start < end){
		for(int i = start;i < end; i++)
			std::cout << line[i] << " - ";
	} else {
		for(int i = start;i < MaxLeght; i++)
			std::cout << line[i] << " - ";
		for(int i = 0;i < end; i++)
			std::cout << line[i] << " - ";
	}
	
	std::cout << std::endl;
}

int main(void){
	ShowLine();
	AddToLine(1);
	AddToLine(2);
	AddToLine(3);
	AddToLine(4);
	ShowLine();
	AddToLine(5);
	RemoveFromLine();
	ShowLine();
	RemoveFromLine();
	ShowLine();
	RemoveFromLine();
	ShowLine();
	RemoveFromLine();
	ShowLine();
	RemoveFromLine();
	RemoveFromLine();

	return 0;
}
