#include "HumanB.hpp"

void HumanB::attack()
{
	if (weapon != nullptr) //&& weapon->getType() != ""
		std::cout << name << "  attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << "  attacks with their " << "hand" << std::endl;
}
void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

HumanB::HumanB(const std::string& name) : weapon(nullptr){
	if (name.empty())
		this->name = "unknown";
	else
		this->name = name;
}