#include <iostream>
#include <print>
using namespace std;

class Base{
public:
    virtual ~Base() = default;
};

class Derived : public Base{
public:
    void hello() const { std::println("Hello From Derived!"); }
};

class Unrelated{};

enum class MyEnum { ENUM_0 };

// static_cast é para:
// - Conversão numerica (int -> float)
// - Ponteiros entre tipos relacionados (upcast/downcast)
// - Void <-> T* (quando o tipo é conhecido)

void demo_static_cast() {
    int a = 42;
    [[maybe_unused]]double b = static_cast<double>(a);
    a = static_cast<int>(b);

    Base *base = new Derived();
    Derived *derived = static_cast<Derived*>(base);
    derived->hello();

    Derived *der = new Derived();
    [[maybe_unused]]Base *bas = static_cast<Base*>(der);

    void *vpInt = new int(10);
    int *pInt = static_cast<int*>(vpInt);

    [[maybe_unused]]int myEnum0 = static_cast<int>(MyEnum::ENUM_0);

    delete base;
    delete der;
    delete pInt;
}

int main()
{
    cout << "static_cast" << endl;
    return 0;
}
