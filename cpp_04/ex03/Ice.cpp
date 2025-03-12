#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Default constructor of Ice is called" << std::endl;
}
Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << "Copy constructor of Ice called" << std::endl;
}
Ice& Ice::operator=(const Ice& other) {
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}
Ice::~Ice() {
	std::cout << "Default destructor of Ice is called" << std::endl;
}

AMateria*	Ice::clone() const {
	std::cout << "Ice clone was called" << std::endl;
	return (new Ice(*this));

}
void	Ice::use(ICharacter& target) {
	std::cout << "Ice use was called" << std::endl;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}