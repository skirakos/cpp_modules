#include "AMateria.hpp"
#include "Ice.hpp"

AMateria::AMateria(std::string const & type) {
	this->type = type;
}

std::string const & AMateria::getType() const {
	return this->type;
} //Returns the materia type

//virtual void use(ICharacter& target);

AMateria::AMateria() {
	std::cout << "Default constructor of AMateria is called" << std::endl;
}
AMateria::AMateria(const AMateria& other) {
	this->type = other.type;
}
AMateria& AMateria::operator=(const AMateria& other) {
	this->type = other.type;
	return (*this);
}
void	AMateria::use(ICharacter& target) {
	std::cout << "* AMateria use was called --> " << target.getName() << " *" << std::endl;
}
AMateria::~AMateria() {
	std::cout << "Default destructor of AMateria is called" << std::endl;
}
