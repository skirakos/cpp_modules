#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string.h>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string name;
	public:
		Weapon weapon;
		const std::string& getType();
		void attack();
		HumanA (const std::string& name, Weapon& weapon);
};

#endif