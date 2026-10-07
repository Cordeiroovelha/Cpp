#ifndef TIME_HPP
#define TIME_HPP

class Time
{
private:
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
public:
    explicit Time();
    void setTime(int hour, int minute, int second);
    void printUniversal();
    void printStandard();
    ~Time();
};

#endif