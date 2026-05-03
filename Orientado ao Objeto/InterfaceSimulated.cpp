// mesmo c++ não possuindo suporte nativo a interfaces
// podemos simular o comportamento de interfaces utilizando classes abstratas

#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

class ITimer {
protected:
    virtual void onTick() = 0;
public:
    virtual void start(const int ms) = 0;
};


class Timer : ITimer{
public:
    void start(const int ms) override{
        while(true) {
            onTick();
            std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        }
    }
};

class TimerSMS : public Timer {
protected:
    void onTick() override {
        std::cout << "CHecking for new SMS..." << std::endl;
    }
};

class TimerEmail : public Timer {
protected:
    void onTick() override {
        std::cout << "CHecking for new emails..." << std::endl;
    }
};

int main()
{
    TimerSMS timer;
    timer.start(1000);
    return 0;
}
