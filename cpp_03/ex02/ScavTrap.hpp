#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <cmath>

class ScavTrap : public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(std::string new_name);
		ScavTrap(ScavTrap& other);
		ScavTrap& operator=(ScavTrap& original);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void guardGate();
		~ScavTrap();
};

#endif