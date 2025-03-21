#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

Bureaucrat::Bureaucrat() {
    std::cout<<"Bureaucrat constructor is called!\n";
}
Bureaucrat::Bureaucrat(std::string new_name, int new_grade) : name(new_name) {
    if (new_grade < 1)
        throw GradeTooHighException();
    if (new_grade > 150)
        throw GradeTooLowException();
    this->grade = new_grade;

}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
    std::cout<<"Bureaucrat copy constructor is called!\n";
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& original) {
    std::cout << "Copy assignment of Bureaucrat operator called\n";
    if (&original != this) {
        this->grade = original.grade;
    }
    return (*this);
}

const std::string Bureaucrat::getName() const {
    std::cout << "Bureaucrat getName was called" << std::endl;
    return this->name;
}
int Bureaucrat::getGrade() const {
    std::cout << "Bureaucrat getGrade was called" << std::endl;
    return this->grade;
}

void Bureaucrat::increment() {
    if (--grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement() {
    if (++(this->grade) > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}

Bureaucrat::~Bureaucrat() {
    std::cout<<"Bureaucrat decstructor is called!\n";
}