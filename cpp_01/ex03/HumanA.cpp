#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout<<name + " attacks with their " + weapon.getType() <<std::endl;
}
//Since references must be initialized when declared, we cannot assign a value to ref inside the constructor body.
//Because references cannot be reassigned, we must initialize them in the constructor's initializer list.
HumanA::HumanA (const std::string& name, Weapon& weapon) : weapon(weapon) // constructor initializer list
{
	this->name = name;
	// this->weapon = weapon;
}
//If you try to assign a reference inside the constructor body instead of using an initializer list, you will get an error.

//we also need to use list with const, since they cannot be assigned after declaration