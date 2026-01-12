// Programa que calcula a equação de fibonacci
// escrito em cpp
// por Murilo Juttel Cordeiro

#include <iostream>
#include <cmath>

using std::cout;

uint_fast64_t fibonacci_base(uint_fast64_t i, uint_fast64_t x, uint_fast64_t y){
    if (i == 0)
        return x;
    else if (i == 1) 
        return y;
    return fibonacci_base(i - 1, y, x + y);
}

uint_fast64_t fibonacci(uint_fast64_t i){
    return fibonacci_base(i, 0, 1);
}

int main(void) {
    cout << "===Fibonacci 1-1000===";
    cout << "\nAperte <enter> para comecar...";
    std::cin.get();
    for (uint_fast64_t i = 0; i <= 1000; i++)
        cout << "f(" << i << ") = " << fibonacci(i) << "\n";
    cout << "Aperte <enter> para encerrar...";
    std::cin.get();
    return 0;
}
