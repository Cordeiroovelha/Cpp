// exemplo de uso de mutex com a biblioteca <mutex>

// mu.lock -> controle manual, precisa de muita atenção
// unique_lock -> controle automático, porem com um alto consumo de recursos
// lock_guard -> controle automático, que bloqueia na criação e desbloqueia na destruição do objeto

#include <chrono>
#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

class ITimer {
protected:
    virtual void onTick() = 0;
public:
    virtual void start(const int ms) = 0;
};


class Timer : ITimer{
public:
    void start(const int ms) final{
        while(true) {
            onTick();
            std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        }
    }
};

// criação de um mutex global
std::mutex mu;

class TimerSMS : public Timer {
protected:
    void onTick() override {
        mu.lock(); // bloqueia o mutex para garantir que apenas uma thread acesse a seção crítica
        std::cout << "CHecking for new SMS..." << std::endl;
        mu.unlock(); // desbloqueia o mutex para permitir que outras threads acessem a seção crítica
    }
};

class TimerEmail : public Timer {
protected:
    void onTick() override {
        std::unique_lock guard(mu); // unique_lock é uma classe que gerencia o bloqueio e desbloqueio do mutex automaticamente
        std::cout << "CHecking for new emails..." << std::endl;
        guard.unlock(); // pode ser retirado por conta do unique_lock
    }
};

class TimerMessenger : public Timer {
protected:
    void onTick() override {
        // diferente do unique_lock, o lock_guard bloqueia no momento da criação e 
        // desbloqueia automaticamente quando o objeto é destruído
        std::lock_guard guard(mu); 
        std::cout << "CHecking for new messenger messages..." << std::endl;
    }
};

int main() {

    TimerEmail timerEmail;
    TimerSMS timerSMS;
    TimerMessenger timerMessenger;

    std::thread thEmail([&timerEmail] {
        timerEmail.start(1000);
    });

    std::thread thSMS([&timerSMS] {
        timerSMS.start(1000);
    });

    std::thread thMessenger([&timerMessenger] {
        timerMessenger.start(1000);
    });

    thEmail.join();
    thSMS.join();
    thMessenger.join();

    return 0;
}
