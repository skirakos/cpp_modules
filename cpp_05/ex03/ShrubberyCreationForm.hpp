#ifndef SHURBERRY_HPP
#define SHURBERRY_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm{
	private:
		std::string   target;

	public:
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& original);

		void		execute(Bureaucrat const & executor) const;
		~ShrubberyCreationForm();
};


#endif