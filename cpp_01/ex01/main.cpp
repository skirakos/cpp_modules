#include "zombie.hpp"

int main()
{
	Zombie *zombies = zombieHorde(-1, "Foo");
	delete []zombies;
	return(0);
}