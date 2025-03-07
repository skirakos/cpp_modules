#include "Animal.hpp"
 
Animal::Animal() {
	std::cout<<"Constructor is called\n";
	this->type = "no_type";
}

Animal::Animal(Animal& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->type = other.type;
	//*this = other; this is also correct but during allocation will be incorrect
}

Animal& Animal::operator=(Animal& original) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &original)
		return (*this);
	this->type = original.type;

	return (*this);
}

Animal::~Animal() {
	std::cout<<"Destuctor is called\n";
}
std::string	Animal::getType() const{
	return (this->type);
}

void Animal::makeSound() const{
	std::cout << "No soundd\n";
}
