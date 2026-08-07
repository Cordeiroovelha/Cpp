#include <print>
using namespace std;

// const_cast é para:
// - remover ou adicionar const
// - util quando lidando com APIs legados
// - undefiden behaviorse modificar um objeto que era originalmente const

void demo_const_cast() {
    const int x = 105;
    int *p = const_cast<int*>(&x);
    println("{}", *p);

    int y = 30;
    const int *py = &y;
    int *pyNoConst = const_cast<int*>(py);
    *pyNoConst = 40;
    println("y: {}", y);
    println("*pyNonConst: {}", *pyNoConst);
}


int main()
{
    demo_const_cast();
    return 0;
}