#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cmath>

class ClapTrap {
	private:
		std::string					name;
		unsigned int				hit_points;
		unsigned int				energy_points;
		unsigned int				attack_damage;

	public:
		ClapTrap();
		ClapTrap(std::string new_name);
		ClapTrap(ClapTrap& other);
		ClapTrap& operator=(ClapTrap& original);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		~ClapTrap();
};

#endif