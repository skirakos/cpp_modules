#ifndef ROBOTO_HPP
#define ROBOTO_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include "AForm.hpp"


class RobotomyRequestForm : public AForm{
	private:
		std::string   target;

	public:
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& original);

		void		execute(Bureaucrat const & executor) const;
		~RobotomyRequestForm();
};


#endif