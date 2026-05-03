// uso da biblioteca <atomic>

#include <chrono>
#include <thread>
#include <iostream>
#include <atomic>

constexpr int total = 100'000'000;
std::atomic_int counter{0};

void func() {
    for (int i = 0; i < total; i++) {
        ++counter;
    }
}

int main(void) {
    auto begin = std::chrono::high_resolution_clock::now();

    std::thread th1(func);
    std::thread th2(func);
    th1.join();
    th2.join();

    auto end = std::chrono::high_resolution_clock::now();
    double totalElapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

    std::cout << "Counter: " << counter.load() << std::endl;
    std::cout << "Total elapsed time: " << totalElapsedTime << std::endl;
}