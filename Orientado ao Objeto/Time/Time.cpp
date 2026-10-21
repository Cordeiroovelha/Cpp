#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <compare>
#include <cstdint>
#include "Time.hpp"

Time::Time() : hour(0), minute(0), second(0)  {
    setTime(hour, minute, second);
}

void Time::setTime(int hour, int minute, int second) {
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

void Time::printUniversal(){
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ':' 
                                   << std::setw(2) << getMinute() << ':' 
                                   << std::setw(2) << getSecond();
}

void Time::printStandard() {
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) 
                                   << std::setfill('0') << std::setw(2) << ':' 
                                   << getMinute() << ':' << std::setw(2) << getSecond()
                                   << (getHour() < 12 ? " AM" : " PM");
}

void Time::setHour(int h){
    if(h >= 0 && h < 24)
        hour = h;
    else
        throw std::invalid_argument("Hour must be 0-23");
    
}
void Time::setMinute(int m){
    if(m >= 0 && m < 60)
        minute = m;
    else
        throw std::invalid_argument("minutes must be 0-59");
    
}
void Time::setSecond(int s){
    if(s >= 0 && s < 60)
        second = s;
    else
        throw std::invalid_argument("seconds must be 0-59");
    
}
constexpr unsigned int Time::getHour(){
    return hour;
}
constexpr unsigned int Time::getMinute(){
    return minute;
}
constexpr unsigned int Time::getSecond(){
    return second;
}