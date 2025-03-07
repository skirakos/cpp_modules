#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* brain;
	public:
		Cat();
		//Cat(std::string new_name);
		Cat(Cat& other);
		Cat& operator=(Cat& original);
		void	makeSound() const;
		virtual ~Cat();
};

#endif