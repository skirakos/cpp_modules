#include "Brain.hpp"
 
Brain::Brain() {
	std::cout<<"Brain constructor is called\n";

}

Brain::Brain(Brain& other) {
	
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
	//*this = other; this is also correct but during allocation will be incorrect
}

Brain& Brain::operator=(Brain& original) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &original)
		return (*this);
	for (int i = 0; i < 100; i++) {
		ideas[i] = original.ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout<<"Brain Destuctor is called\n";
}