#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <iostream>
#include <stdexcept>
#include <string>

class AForm {
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
		AForm();
		AForm(std::string newName, int newGradeS, int newGradeE);
		AForm(const AForm& other);
		AForm& operator=(const AForm& original);

		const std::string getName() const;
        bool                getIsSigned() const;
        const int           getGradeToSign() const;
        const int           getGradeToExecute() const;
        virtual void    beSigned(Bureaucrat& obj) = 0;
        virtual void		executeForm(Bureaucrat const & executor) const = 0;
		~AForm();
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif