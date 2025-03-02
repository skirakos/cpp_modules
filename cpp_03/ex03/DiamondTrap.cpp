#include "DiamondTrap.hpp"

 
DiamondTrap::DiamondTrap() {
	std::cout<<"DiamondTrap Constructor is called\n";
	this->name = "Unknown";
	this->ClapTrap::name = "Unknown_clap_name";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap& other) {
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& original) {
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this == &original)
		return (*this);
	this->name = original.name;
	this->hit_points = original.hit_points;
	this->energy_points = original.energy_points;
	this->attack_damage = original.attack_damage;

	return (*this);
}
DiamondTrap::DiamondTrap(std::string new_name){
	std::cout<<"DiamondTrap Parameter constructor is called\n";
	this->name = new_name;
	this->ClapTrap::name = new_name + "_clap_name";
	this->hit_points = this->FragTrap::hit_points;
	this->energy_points = this->ScavTrap::energy_points;
	this->attack_damage = this->FragTrap::attack_damage;
}

DiamondTrap::~DiamondTrap() {
	std::cout<<"DiamondTrap Destuctor is called\n";
}


void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}
void DiamondTrap::takeDamage(unsigned int amount) {
	if (this->energy_points == 0)
		std::cout<<"No more energy points for "<<this->name<<std::endl;

	if (this->hit_points == 0)
		std::cout<<this->name<<" is already died\n";
	else {
		std::cout << "DiamondTrap " << this->name << " has got " << amount << " damages!" << std::endl;
		if (amount >= this->hit_points)
			this->hit_points -= amount;
		else this->hit_points = 0;
	}
}
void DiamondTrap::beRepaired(unsigned int amount) {
	if (this->energy_points == 0)
		std::cout << "DiamondTrap " << this->name << " out of energy." << std::endl;

	std::cout<<this->name<<" is repaired.\n";
	this->hit_points += amount;
	if (this->energy_points >= 1)
		this->energy_points--;
	else
		std::cout<<"No more energy points for "<<this->name<<std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout<< this->name << " " <<this->ClapTrap::name <<std::endl;
}