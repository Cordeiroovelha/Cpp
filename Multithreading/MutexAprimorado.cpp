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

    virtual ~ITimer() = default;
};


class Timer : ITimer{
public:
    void start(const int ms){
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

template <typename T>
concept DerivedFromTime = std::is_base_of_v<Timer, T>;

template <DerivedFromTime TIMER>
class TimerTS : public TIMER {
    std::unique_ptr<std::thread> m_thread{nullptr};
    std::mutex &m_mutex;
public:
    TimerTS(TimerTS &&) = delete;
    TimerTS(const TimerTS &) = delete;
    TimerTS &operator=(TimerTS &&) = delete;
    TimerTS &operator=(const TimerTS &) = delete;

    explicit TimerTS(std::mutex &mu) : m_mutex(mu) {}

    ~TimerTS() {
        if (m_thread && m_thread->joinable())
            m_thread->join();
    }

    void onTick() override {
        std::lock_guard guard(m_mutex);
        TIMER::onTick();
    }

    void start(int ms) override {
        if(m_thread)
            return;

        m_thread = std::make_unique<std::thread>([this, ms] {TIMER::start(ms);});
    }

};


int main() {

    std::mutex mu;
    TimerTS<TimerEmail> timerEmail(mu);
    TimerTS<TimerSMS> timerSMS(mu);

    std::thread thEmail([&timerEmail] {
        timerEmail.start(1000);
    });

    std::thread thSMS([&timerSMS] {
        timerSMS.start(1000);
    });

    thEmail.join();
    thSMS.join();

    return 0;
}
