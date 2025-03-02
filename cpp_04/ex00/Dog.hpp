#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {
	public:
		Dog();
		//Dog(std::string new_name);
		Dog(Dog& other);
		Dog& operator=(Dog& original);
		void	makeSound() const;
		virtual ~Dog();
};

#endif