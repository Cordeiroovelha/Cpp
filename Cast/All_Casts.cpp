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
    std::println("{}", a);

    delete base;
    delete der;
    delete pInt;
}

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

// reinterpret_cast é usado para:
// converção de baixo nivel entre tipos não relacionados
// PERIGOSO: pode causar undefined behavior

void demo_reinterpret_cast() {
    int value = 123;
    char * byteView = reinterpret_cast<char*>(&value);
    std::println("First byte of value: {}", static_cast<int>(byteView[0]));

    int *intPtr = &value;
    [[maybe_unused]]float * floatPtr = reinterpret_cast<float*>(intPtr);
    // std::println("{}", *floatPtr);   // PROIBIDO -> indefined behavior

    uintptr_t raw = reinterpret_cast<uintptr_t>(intPtr);
    int *restored = reinterpret_cast<int*>(raw);
    std::println("restored value: {}", *restored);
}

//dynamc_cast é usado para:
// fazer downcast de maneira segura em hierarquias polimorfas
// requer a utilização de funçoes virtuais
// funciona com ponteiros e referencias
// ! mais lenta que outros cast

void demo_dynamic_cast(){
    Base *base = new Derived();
    Derived *derived = dynamic_cast<Derived*>(base);
    if (derived)
        derived->hello();

    Base *base2 = new Derived();
    Derived *derived2 = dynamic_cast<Derived*>(base);
    if (derived2)
        derived2->hello();

    try {
        Base &ref = *base2;
        Derived &refCast = dynamic_cast<Derived&>(ref); // !BAD_CAST
        refCast.hello();
    } catch (const std::bad_cast &ex) {
        std::println("bad_cast exception: {}", ex.what());
    }

    try {
        Base &ref = *base;
        Derived &refCast = dynamic_cast<Derived&>(ref); // Cast Valido
        refCast.hello();
    } catch (const std::bad_cast &ex) {
        std::println("bad_cast exception: {}", ex.what());
    }

    delete base;
    delete base2;
}

int main() {
    println("=== static_cast ===");
    demo_static_cast();
    println("");

    println("=== const_cast ===");
    demo_const_cast();
    println("");

    println("=== reinterpret_cast ===");
    demo_reinterpret_cast();
    println("");

    println("=== dynamic_cast ===");
    demo_dynamic_cast();
    println("");

    return 0;
}