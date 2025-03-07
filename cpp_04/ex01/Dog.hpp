#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
	private:
		Brain* brain;
	public:
		Dog();
		//Dog(std::string new_name);
		Dog(Dog& other);
		Dog& operator=(Dog& original);
		void	makeSound() const;
		virtual ~Dog();
};

#endif