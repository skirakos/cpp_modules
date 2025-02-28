#include "FragTrap.hpp"

 
FragTrap::FragTrap() {
	std::cout<<"FragTrap Constructor is called\n";
	this->name = "Unknown";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(FragTrap& other) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(FragTrap& original) {
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this == &original)
		return (*this);
	this->name = original.name;
	this->hit_points = original.hit_points;
	this->energy_points = original.energy_points;
	this->attack_damage = original.attack_damage;

	return (*this);
}
FragTrap::FragTrap(std::string new_name){
	std::cout<<"FragTrap Parameter constructor is called\n";
	this->name =new_name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::~FragTrap() {
	std::cout<<"FragTrap Destuctor is called\n";
}


void FragTrap::attack(const std::string& target) {
	if (this->energy_points == 0)
		std::cout<<"No more energy points for "<<this->name<<std::endl;

	std::cout << "FragTrap "<< this->name << " attacks "<< target<< ", causing " << this->attack_damage <<" points of damage!\n";
	if (this->energy_points >= 1)
		this->energy_points--;
	else
		std::cout<<"No more energy points for \n"<<this->name;
}
void FragTrap::takeDamage(unsigned int amount) {
	if (this->energy_points == 0)
		std::cout<<"No more energy points for "<<this->name<<std::endl;

	if (this->hit_points == 0)
		std::cout<<this->name<<" is already died\n";
	else {
		std::cout << "FragTrap " << this->name << " has got " << amount << " damages!" << std::endl;
		if (amount >= this->hit_points)
			this->hit_points -= amount;
		else this->hit_points = 0;
	}
}
void FragTrap::beRepaired(unsigned int amount) {
	if (this->energy_points == 0)
		std::cout << "FragTrap " << this->name << " out of energy." << std::endl;

	std::cout<<this->name<<" is repaired.\n";
	this->hit_points += amount;
	if (this->energy_points >= 1)
		this->energy_points--;
	else
		std::cout<<"No more energy points for "<<this->name<<std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout<<this->name<<" send high five request to members!\n";
}