#ifndef GRADEBOOK_HPP
#define GRADEBOOK_HPP

#include <string>

class GradeBook
{
private:
    std::string CourseName; // nome do curso
public:
    explicit GradeBook(std::string name);  // construtor
    void setCourseName(std::string name);  // setter
    const std::string getCourseName();     // Getter
    void displayMessage();           // exibe mensagem de boas vindas
    ~GradeBook();                          // destrutor
};

#endif