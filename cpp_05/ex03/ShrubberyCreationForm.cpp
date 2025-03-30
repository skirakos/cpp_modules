#include "ShrubberyCreationForm.hpp"

const char* ShrubberyCreationForm::FormNotSignedException::what() const throw() {
    return "The form is not signed !!";
}
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("unknown_Shrubbery") {
    std::cout<<"ShrubberyCreationForm constructor is called!\n";
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
    std::cout<<"ShrubberyCreationForm constructor with parameters is called!\n";
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original) {
    std::cout << "Copy assignment of ShrubberyCreationForm operator called\n";
    if (&original != this) {
        AForm::operator=(original);
        this->target = original.target;
    }
    return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
    }

    std::ofstream outFile(this->target + "_shrubbery");
    if (!outFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return ;
    }

    const std::string content = 
        "        /\\\n"
        "       /**\\\n"
        "      /****\\\n"
        "     /******\\\n"
        "    /********\\\n"
        "   /**********\\\n"
        "  /************\\\n"
        " /**************\\\n"
        "/****************\\\n"
        "       ||\n"
        "       ||\n";

    outFile << content;
    outFile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout<<"ShrubberyCreationForm decstructor is called!\n";
}