#include "ShrubberyCreationForm.hpp"

// const std::string   name;
//         bool                isSigned;
//         const int           gradeToSign;
//         const int           gradeToExecute;
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("unknown") {
    std::cout<<"ShrubberyCreationForm constructor is called!\n";
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target() {
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

void		execute(Bureaucrat const & executor) {
    std::ofstream outFile(this->target + "_shrubbery");

    if (!outFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return ;
    }

    // Write data to the file
    outFile << "Hello, this is a test message!" << std::endl;
    outFile << "Writing to a file in C++ is easy." << std::endl;

    // Close the file after writing
    outFile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout<<"ShrubberyCreationForm decstructor is called!\n";
}