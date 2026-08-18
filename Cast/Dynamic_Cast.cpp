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
    
    println("=== dynamic_cast ===");
    demo_dynamic_cast();
    println("");

    return 0;
}