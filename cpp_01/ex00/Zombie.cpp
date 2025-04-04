#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout<<name<<std::endl;
}

void Zombie::setName(std::string new_name)
{
	name = new_name;
}

void Zombie::announce( void )
{
	std::cout<< name + ": " + "BraiiiiiiinnnzzzZ..."<<std::endl;
}