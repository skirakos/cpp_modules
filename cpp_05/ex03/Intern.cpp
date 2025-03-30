#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {
    std::cout<<"Intern constructor is called!\n";
}
Intern::Intern(const Intern& other) {
    std::cout<<"Intern copy constructor is called!\n";
    *this = other;
}
Intern& Intern::operator=(const Intern& original) {
    std::cout << "Copy assignment of Intern operator called\n";
    if (&original != this) {
        
    }
    return (*this);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    std::string arr[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int n = -1;
    for (int i = 0; i < 4; i++) {
        if (arr[i] == name) {
            n = i;
        }
    }
    switch (n)
    {
        case 0:
            std::cout<<"Intern creates ShrubberyCreationForm"<<std::endl;
            return (new ShrubberyCreationForm(target));
        case 1:
            std::cout<<"Intern creates RobotomyRequestForm"<<std::endl;
            return (new RobotomyRequestForm(target));
        case 2:
            std::cout<<"Intern creates PresidentialPardonForm"<<std::endl;
            return (new PresidentialPardonForm(target));
        default:
            std::cout<<"no such form type.\n";
            return (NULL);
    }
    
}

Intern::~Intern() {
    std::cout<<"Intern decstructor is called!\n";
}