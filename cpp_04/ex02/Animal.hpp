#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string					type;

	public:
		Animal();
		Animal(Animal& other);
		Animal& operator=(Animal& original);
		std::string	getType() const;
		virtual	void	makeSound() const =0;
		virtual ~Animal();
};

#endif