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
        
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& original);

		void		execute(Bureaucrat const & executor);
		~ShrubberyCreationForm();
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& obj);

#endif