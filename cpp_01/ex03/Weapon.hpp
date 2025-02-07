#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string.h>
#include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		Weapon();
		Weapon(const std::string& newType);
		const std::string& getType();
		void setType(const std::string& newType);
};

#endif