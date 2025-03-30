#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <iostream>
#include <stdexcept>
#include <string>

class AForm;

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& original);

		AForm* makeForm(const std::string& name, const std::string& target);
		~Intern();
};

#endif