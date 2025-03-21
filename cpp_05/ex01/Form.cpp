#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}
const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}
// const std::string   name;
//         bool                isSigned;
//         const int           gradeToSign;
//         const int           gradeToExecute;
Form::Form() : isSigned(false),  gradeToExecute(1), gradeToSign(1){
    std::cout<<"Form constructor is called!\n";
}
Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {

    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}
Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    std::cout<<"Form copy constructor is called!\n";
}
Form& Form::operator=(const Form& original) {
    std::cout << "Copy assignment of Form operator called\n";
    if (&original != this) {
        this->isSigned = original.isSigned;
    }
    return (*this);
}

const std::string Form::getName() const {
    std::cout << "Form getName was called" << std::endl;
    return this->name;
}
const int Form::getGradeToSign() const {
    std::cout << "Form getGrade was called" << std::endl;
    return this->gradeToSign;
}

const int Form::getGradeToExecute() const {
    std::cout << "Form getGrade was called" << std::endl;
    return this->gradeToExecute;
}
bool Form::getIsSigned() const {
    std::cout << "Form getIsSigned was called" << std::endl;
    return isSigned;
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << obj.getName() << ", Form gradeS " << obj.getGradeToSign() << ", gradeE " << obj.getGradeToExecute() << ", isSigned "<<obj.getIsSigned() ;
    return os;
}
void    Form::beSigned(Bureaucrat& obj) {
    if (obj.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    else
        this->isSigned = true;
}
Form::~Form() {
    std::cout<<"Form decstructor is called!\n";
}