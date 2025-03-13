#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Default constructor of Cure is called" << std::endl;
}
Cure::Cure(const Cure& other) : AMateria(other) {
	std::cout << "Copy constructor of Cure called" << std::endl;
}
Cure& Cure::operator=(const Cure& other) {
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}
Cure::~Cure() {
	std::cout << "Default destructor of Cure is called" << std::endl;
}

AMateria*	Cure::clone() const {
	std::cout << "Cure clone was called" << std::endl;
	return (new Cure(*this));

}
void	Cure::use(ICharacter& target) {
	std::cout << "Cure use was called" << std::endl;
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}