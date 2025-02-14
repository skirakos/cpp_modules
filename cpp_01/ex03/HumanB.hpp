#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string.h>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon* weapon;
	public:
		void attack(); //why const
		void setWeapon(Weapon& weapon);
		HumanB(const std::string& name);
};

#endif