#include "PresidentialPardonForm.hpp"

const char* PresidentialPardonForm::FormNotSignedException::what() const throw() {
    return "The form is not signed !!";
}
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("unknown_President") {
    std::cout<<"PresidentialPardonForm constructor is called!\n";
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 145, 137), target(target) {
    std::cout<<"PresidentialPardonForm constructor with parameters is called!\n";
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& original) {
    std::cout << "Copy assignment of PresidentialPardonForm operator called\n";
    if (&original != this) {
        AForm::operator=(original);
        this->target = original.target;
    }
    return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
    }

    std::cout<<target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout<<"ShrubberyCreationForm decstructor is called!\n";
}