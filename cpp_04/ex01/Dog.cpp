#include "Dog.hpp"
 
Dog::Dog() {
	std::cout<<"Dog Constructor is called\n";
	brain = new Brain();
	this->type = "dog";
}
// Copy constructor (deep copy)
Dog::Dog(Dog& other) {
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain); // Deep copy using Brain's copy constructor
}

// Copy assignment operator (deep copy)
Dog& Dog::operator=(Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) { // Self-assignment check
        delete brain; // Free existing memory
        brain = new Brain(*other.brain); // Deep copy
    }
    return *this; // Return reference to allow chaining (e.g., a = b = c)
}
// Dog::Dog(Dog& other) {
// 	std::cout << "Dog Copy constructor called" << std::endl;
// 	*this = other;
// }

// Dog& Dog::operator=(Dog& original) {
// 	std::cout << "Dog Copy assignment operator called" << std::endl;
// 	if (this == &original) 
// 		return (*this);
// 	this->type = original.type;
// 	return (*this);
// }

Dog::~Dog() {
	std::cout<<"Dog Destuctor is called\n";
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "Haf\n";
}
