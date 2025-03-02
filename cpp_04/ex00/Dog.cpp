#include "Dog.hpp"
 
Dog::Dog() {
	std::cout<<"Constructor is called\n";
	this->type = "dog";
}

Dog::Dog(Dog& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(Dog& original) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &original)
		return (*this);
	this->type = original.type;
	return (*this);
}

Dog::~Dog() {
	std::cout<<"Destuctor is called\n";
}

void Dog::makeSound() const {
	std::cout << "Haf\n";
}
