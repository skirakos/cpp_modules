#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(){
	this->name = "unknown";
	std::cout << "Default constructor of Character is called" << std::endl;
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(std::string const & name) {
	this->name = name;
	std::cout << "Parameter constructor of Character is called" << std::endl;
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(const Character& other) {
	std::cout << "Copy constructor of Character is called" << std::endl;
	name = other.name;
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}
Character& Character::operator=(const Character& other) {
	std::cout << "Assignement operator of Character is called" << std::endl;
	name = other.name;
	for (int i = 0; i < 4; i++) {
		if (inventory[i])
				delete inventory[i];
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	return (*this);
}

Character::~Character() {
	std::cout << "Default destructor of Character is called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (inventory[i])
			delete inventory[i];
	}
}

std::string const &	Character::getName() const {
	return this->name;
}

void	Character::equip(AMateria* m) {
	std::cout << "Character equip was called" << std::endl;
	if (!m)
		return ;

	int	i = 0;
	while (this->inventory[i]) {
		i++;
	}
	if (i <= 3)
		this->inventory[i] = m;
}

void	Character::unequip(int idx) {
	std::cout << "Character unequip was called" << std::endl;
	if (idx >=0 && idx < 4 && this->inventory[idx])
		this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	std::cout << "Character use was called" << std::endl;
	if (idx >= 0 &&  idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}