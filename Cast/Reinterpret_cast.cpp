#include <print>
using namespace std;

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

int main() {    
    println("reinterpret_cast");
    demo_reinterpret_cast();
    
    return 0;
}