#include <iostream>
#include <string>
#include "gradeBook.hpp"

GradeBook::GradeBook(std::string name) : CourseName(name) {
    setCourseName(name);
}

void GradeBook::setCourseName(std::string name){
    if(name.size() <= 25)
        CourseName = name;
    else{
        CourseName = name.substr(0, 24);
        std::cerr << "Warning: name \"" << name << "\" exceeds maximum length (25)";
    }
        
    CourseName = name;
}

const std::string GradeBook::getCourseName() {
    return CourseName;
}

void GradeBook::displayMessage() {
    std::cout << "Welvome to  the GradeBook for " << getCourseName() << std::endl;
}

GradeBook::~GradeBook() {}