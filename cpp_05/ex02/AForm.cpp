#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}
const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}
const char* AForm::FormNotSignedException::what() const throw() {
    return "The form is not signed !!";
}

AForm::AForm() : isSigned(false), gradeToSign(1), gradeToExecute(1) {
    //std::cout<<"AForm constructor is called!\n";
}
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {

    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}
AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    //std::cout<<"AForm copy constructor is called!\n";
}
AForm& AForm::operator=(const AForm& original) {
    std::cout << "Copy assignment of AForm operator called\n";
    if (&original != this) {
        this->isSigned = original.isSigned;
    }
    return (*this);
}

const std::string AForm::getName() const {
    //std::cout << "AForm getName was called" << std::endl;
    return this->name;
}
int AForm::getGradeToSign() const {
    //std::cout << "AForm getGrade was called" << std::endl;
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
    //std::cout << "AForm getGrade was called" << std::endl;
    return this->gradeToExecute;
}
bool AForm::getIsSigned() const {
    //std::cout << "AForm getIsSigned was called" << std::endl;
    return isSigned;
}

std::ostream& operator<<(std::ostream& os, const AForm& point) {
    os << "AForm name : " << point.getName() << ", Grade to sign : " << \
            point.getGradeToSign() << ", Grade to execute : " << point.getGradeToExecute() \
            << ", AForm " << (point.getIsSigned() == true ? "is signed" : ", is not signed");
    return os;
}
void    AForm::beSigned(Bureaucrat& obj) {
    if (obj.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    else
        this->isSigned = true;
}
void		AForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
    }
}
AForm::~AForm() {
    std::cout<<"AForm decstructor is called!\n";
}