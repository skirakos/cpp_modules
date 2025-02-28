#include "ClapTrap.hpp"

 
ClapTrap::ClapTrap() {
	std::cout<<"Constructor is called\n";
	this->name = "Unknown";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(ClapTrap& original) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &original)
		return (*this);
	this->name = original.name;
	this->hit_points = original.hit_points;
	this->energy_points = original.energy_points;
	this->attack_damage = original.attack_damage;

	return (*this);
}
ClapTrap::ClapTrap(std::string new_name){
	std::cout<<"Parameter constructor is called\n";
	this->name =new_name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout<<"Destuctor is called\n";
}


void ClapTrap::attack(const std::string& target) {
	if (this->energy_points == 0)
		std::cout<<"No more energy points for "<<this->name<<std::endl;

	std::cout << "ClapTrap "<< this->name << " attacks "<< target<< ", causing " << this->attack_damage <<" points of damage!\n";
	if (this->energy_points >= 1)
		this->energy_points--;
	else
		std::cout<<"No more energy points for \n"<<this->name;
}
void ClapTrap::takeDamage(unsigned int amount) {
	if (this->energy_points == 0)
		std::cout<<"No more energy points for "<<this->name<<std::endl;

	if (this->hit_points == 0)
		std::cout<<this->name<<" is already died\n";
	else {
		std::cout << "ClapTrap " << this->name << " has got " << amount << " damages!" << std::endl;
		if (amount >= this->hit_points)
			this->hit_points -= amount;
		else this->hit_points = 0;
	}
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy_points == 0)
		std::cout << "ClapTrap " << this->name << " out of energy." << std::endl;

	std::cout<<this->name<<" is repaired.\n";
	this->hit_points += amount;
	if (this->energy_points >= 1)
		this->energy_points--;
	else
		std::cout<<"No more energy points for "<<this->name<<std::endl;
}