#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <iostream>
#include <stdexcept>
#include <string>

class Form {
	private:
		const std::string   name;
        bool                isSigned;
        const int           gradeToSign;
        const int           gradeToExecute;

	public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
		Form();
		Form(std::string newName, int newGradeS, int newGradeE);
		Form(const Form& other);
		Form& operator=(const Form& original);

		const std::string getName() const;
        bool                getIsSigned() const;
        const int           getGradeToSign() const;
        const int           getGradeToExecute() const;
        void    beSigned(Bureaucrat& obj);
		~Form();
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif