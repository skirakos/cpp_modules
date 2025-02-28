#include "ScavTrap.hpp"

 
ScavTrap::ScavTrap() {
	std::cout<<"ScavTrap Constructor is called\n";
	this->name = "Unknown";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap& other) {
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(ScavTrap& original) {
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this == &original)
		return (*this);
	this->name = original.name;
	this->hit_points = original.hit_points;
	this->energy_points = original.energy_points;
	this->attack_damage = original.attack_damage;

	return (*this);
}
ScavTrap::ScavTrap(std::string new_name){
	std::cout<<"ScavTrap Parameter constructor is called\n";
	this->name =new_name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout<<"ScavTrap Destuctor is called\n";
}


void ScavTrap::attack(const std::string& target) {
	if (this->energy_points == 0)
		std::cout<<"No more energy points for "<<this->name<<std::endl;

	std::cout << "ScavTrap "<< this->name << " attacks "<< target<< ", causing " << this->attack_damage <<" points of damage!\n";
	if (this->energy_points >= 1)
		this->energy_points--;
	else
		std::cout<<"No more energy points for \n"<<this->name;
}
void ScavTrap::takeDamage(unsigned int amount) {
	if (this->energy_points == 0)
		std::cout<<"No more energy points for "<<this->name<<std::endl;

	if (this->hit_points == 0)
		std::cout<<this->name<<" is already died\n";
	else {
		std::cout << "ScavTrap " << this->name << " has got " << amount << " damages!" << std::endl;
		if (amount >= this->hit_points)
			this->hit_points -= amount;
		else this->hit_points = 0;
	}
}
void ScavTrap::beRepaired(unsigned int amount) {
	if (this->energy_points == 0)
		std::cout << "ScavTrap " << this->name << " out of energy." << std::endl;

	std::cout<<this->name<<" is repaired.\n";
	this->hit_points += amount;
	if (this->energy_points >= 1)
		this->energy_points--;
	else
		std::cout<<"No more energy points for "<<this->name<<std::endl;
}

void ScavTrap::guardGate() {
	std::cout<<this->name<<" ScavTrap is now in Gate keeper mode\n";
}