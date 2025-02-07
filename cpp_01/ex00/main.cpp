#include "zombie.hpp"

int main()
{
	std::string name_stack;
	std::cout<<"Enter zombie name to keep in stack: ";
	std::cin>>name_stack;
	randomChump(name_stack);

	std::string name_heap;
	std::cout<<"Enter zombie name to keep in heap: ";
	std::cin>>name_heap;
	Zombie *zombie = newZombie(name_heap);
	delete(zombie);
	return(0);
}