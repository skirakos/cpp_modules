#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <cmath>

class FragTrap : virtual public ClapTrap{
	public:
		FragTrap();
		FragTrap(std::string new_name);
		FragTrap(FragTrap& other);
		FragTrap& operator=(FragTrap& original);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void highFivesGuys();
		virtual ~FragTrap();
};

#endif