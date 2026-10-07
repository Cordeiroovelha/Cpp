#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.hpp"

Time::Time() : hour(0), minute(0), second(0)  {}

void Time::setTime(int hour, int minute, int second) {
    if ((hour >= 0 && hour < 24) && (minute >= 0 && minute < 60) && (second >= 0 && second < 60)) {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    } else 
        throw std::invalid_argument("Invalid Time - OOR");
}

void Time::printUniversal(){
    std::cout << std::setfill('0') << std::setw(2) << hour << ':' 
                                   << std::setw(2) << minute << ':' 
                                   << std::setw(2) << second;
}

void Time::printStandard() {
    std::cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) 
                                   << std::setfill('0') << std::setw(2) << ':' 
                                   << std::setw(2) << minute << ':' 
                                   << std::setw(2) << second;
}