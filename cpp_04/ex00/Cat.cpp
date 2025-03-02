#include "Cat.hpp"
 
Cat::Cat() {
	std::cout<<"Constructor is called\n";
	this->type = "cat";
}

Cat::Cat(Cat& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(Cat& original) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &original)
		return (*this);
	this->type = original.type;
	return (*this);
}

Cat::~Cat() {
	std::cout<<"Destuctor is called\n";
}

void Cat::makeSound() const {
	std::cout << "Myau\n";
}
