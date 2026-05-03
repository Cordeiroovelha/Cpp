// exemplo de polimorfismo com single tread

#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

// simulação de interface utilizando classe abstrata
class ITimer {
protected:
    // virtual é uma palavra-chave que indica que a função é que pode ser sobrescrita por classes filhas 
    virtual void onTick() = 0;
public:
    virtual void start(const int ms) = 0;
};


class Timer : ITimer{
public:
    // usa a notação "final" para impedir que a função seja sobrescrita por classes filhas
    void start(const int ms) final{
        while(true) {
            onTick();
            std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        }
    }
};

class TimerSMS : public Timer {
protected:
    // override é uma notação que indica que a função está sobrescrevendo uma função virtual da classe base 
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
