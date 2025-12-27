// exemplo de template em c++ o qual sua função é reconhecer o tipo que ira ser utilizado na função

#include <iostream>

template <typename TYPE> // a palavra "typename" pode ser substituida por "class"

TYPE Maximum(TYPE a, TYPE b)
{
    return a > b ? a : b;
}

int main(void)
{
    int x = 10, y = 11;
    int r = Maximum(x, y);
    std::cout << r << std::endl;
}