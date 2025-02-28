#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {

	// FragTrap a("Bob");

	// a.attack("Josh");
	// a.takeDamage(150);
	// a.beRepaired(15);
	// a.highFivesGuys();

	ClapTrap *a = new FragTrap();
	delete a;
	return (0);
}