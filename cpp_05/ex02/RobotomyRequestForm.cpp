#include "RobotomyRequestForm.hpp"

const char* RobotomyRequestForm::FormNotSignedException::what() const throw() {
    return "The form is not signed !!";
}
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("unknown_Roboto") {
    std::cout<<"RobotomyRequestForm constructor is called!\n";
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 145, 137), target(target) {
    std::cout<<"RobotomyRequestForm constructor with parameters is called!\n";
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& original) {
    std::cout << "Copy assignment of RobotomyRequestForm operator called\n";
    if (&original != this) {
        AForm::operator=(original);
        this->target = original.target;
    }
    return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
    }

    std::cout << "Makes some drilling noises..." << std::endl;
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout<<"ShrubberyCreationForm decstructor is called!\n";
}