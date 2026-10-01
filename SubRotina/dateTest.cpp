// arquivo que usa o Header "date.h" para demonstar suas funçoes

#include "date.h"
#include <print>

int main()
{
    date dt1{1, 1, 2024};
    dt1.printDate();

    //função de troca de data
    dt1.changeDate(1, 1, 2000);
    dt1.printDate();

    //função de reconhecimento de ano bisexto
    if (dt1.isLeapYear())
        std::println("This is a leap year!");
    else
        std::println("This is not a leap year!");

    //função spaceship de sobrecarga de operadores
    date dt2{7,7,2000};
    if (dt1 > dt2)
        std::println("Date 1 > Date 2");
    else
        std::println("Date 1 < Date 2");

    return 0;
}
