#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string.h>
#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		~Zombie();
		void setName(std::string new_name);
		void announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif