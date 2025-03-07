#include "Cat.hpp"
 
Cat::Cat() {
	std::cout<<"Cat Constructor is called\n";
	brain = new Brain();
	this->type = "cat";
}

// Copy constructor (deep copy)
Cat::Cat(Cat& other) {
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*other.brain); // Deep copy using Brain's copy constructor
}

// Copy assignment operator (deep copy)
Cat& Cat::operator=(Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) { // Self-assignment check
        delete brain; // Free existing memory
        brain = new Brain(*other.brain); // Deep copy
    }
    return *this; // Return reference to allow chaining (e.g., a = b = c)
}
// Cat::Cat(Cat& other) {
// 	std::cout << "Cat Copy constructor called" << std::endl;
// 	*this = other;
// }

// Cat& Cat::operator=(Cat& original) {
// 	std::cout << "Cat Copy assignment operator called" << std::endl;
// 	if (this == &original)
// 		return (*this);
// 	this->type = original.type;
// 	return (*this);
// }

Cat::~Cat() {
	std::cout<<"Cat Destuctor is called\n";
	delete brain;
}

void Cat::makeSound() const {
	std::cout << "Myau\n";
}
