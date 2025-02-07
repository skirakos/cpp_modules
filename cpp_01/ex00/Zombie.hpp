#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string.h>
#include <iostream>
#include <stdio.h>

class Zombie {
	private:
		std::string name;
	public:
		~Zombie();
		void setName(std::string new_name);
		void announce( void );
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif