#ifndef DATE_H
#define DATE_H

#include <print>
#include <compare>
#include <cstdint>

class date
{
private:
    uint8_t  m_day : 7;
    uint8_t  m_mouth;
    uint16_t m_year;
    bool m_valid : 1 {false}; // inicialização na propria declaração do tipo
public:
    enum {YEAR_MIN = 1900, YEAR_MAX = 2100 };
    enum { FEBRUARY = 2, JULY = 7};

    date() = default;

    date(uint8_t day, uint8_t mouth, uint16_t year)
    {
        changeDate(day, mouth, year);
    }

    void changeDate(uint8_t day, uint8_t mouth, uint16_t year)
    {
        m_day = day;
        m_mouth = mouth;
        m_year = year;

        validate();
    }

    void validate()
    {
        m_valid = ((m_day >= 1 && m_day <= lastDayOfMonth()) &&
                   (m_mouth >= 1 && m_mouth <= 12) &&
                   (m_year >= YEAR_MIN && m_year <= YEAR_MAX));
    }

    void printDate() const
    {
        if (m_valid)
        {
            std::println("{:02}/{:02}/{}", m_day, m_mouth, m_year);
        }
        else
            std::println("nvalid date!");
    }

    uint8_t lastDayOfMonth() const
    {
        return m_mouth == FEBRUARY ?
                   (30 + (m_mouth & 1) ^ (m_mouth > JULY)) :
                   (28 + isLeapYear());
    }

    bool isLeapYear() const
    {
        return (!(m_year & 3) && (m_year % 100)) || !(m_year % 400);
    }

    uint8_t day() const
    {
        return m_day;
    }

    uint8_t month() const
    {
        return m_mouth;
    }

    uint16_t year() const
    {
        return m_year;
    }

    auto operator<=>(const date &other) const
    {
        if(const auto cmp = m_year <=> other.m_year; cmp != 0) return cmp;
        if(const auto cmp = m_mouth <=> other.m_mouth; cmp != 0) return cmp;
        return m_day <=> other.m_day;
    }

    bool operator==(const date &other) const
    {
        return (*this <=> other) == 0;
    }

};

#endif // DATE_H
