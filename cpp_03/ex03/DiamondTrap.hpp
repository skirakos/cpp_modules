#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <cmath>

class DiamondTrap : public ScavTrap, public FragTrap{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string new_name);
		DiamondTrap(DiamondTrap& other);
		DiamondTrap& operator=(DiamondTrap& original);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void whoAmI();
		virtual ~DiamondTrap();
};

#endif