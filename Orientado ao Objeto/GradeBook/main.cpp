// g++ *.cpp -o app
#include <iostream>
#include "gradeBook.hpp"

int main(void){
    GradeBook gradebook1("CS101 Introduction to C++ Programmming");
    GradeBook gradebook2("CS102 Data Structures in C++");

    std::cout << " * gradeBook1 created for course:" << gradebook1.getCourseName() << std:: endl;
    std::cout << " * gradeBook2 created for course:" << gradebook2.getCourseName() << std:: endl;

    std::cin.get();
    return 0;
}