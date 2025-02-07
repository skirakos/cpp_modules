#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout<<name + "attacks with their" + weapon.getType() <<std::endl;
}
HumanA::HumanA (const std::string& name, Weapon& weapon){
	this->name = name;
	this->weapon = weapon;
}