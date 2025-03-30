#ifndef PRESIDENT_HPP
#define PRESIDENT_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include "AForm.hpp"


class PresidentialPardonForm : public AForm{
	private:
		std::string   target;

	public:
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& original);

		void		execute(Bureaucrat const & executor) const;
		~PresidentialPardonForm();
};

#endif