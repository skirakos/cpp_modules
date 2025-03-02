#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal {
	public:
		Cat();
		//Cat(std::string new_name);
		Cat(Cat& other);
		Cat& operator=(Cat& original);
		void	makeSound() const;
		virtual ~Cat();
};

#endif