#ifndef BUREAUCARAT_HPP
#define BUREAUCARAT_HPP

#include <iostream>
#include <iostream>
#include <stdexcept>
#include <string>

class AForm;

class Bureaucrat {
	private:
		const std::string   name;
		int                 grade;

	public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
		Bureaucrat();
		Bureaucrat(std::string new_name, int new_grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& original);

		const std::string getName() const;
		int getGrade() const;
		void increment();
		void decrement();
		void    signForm(AForm& form);
		void	executeForm(AForm const & form);
		~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif