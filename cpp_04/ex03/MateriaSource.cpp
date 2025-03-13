#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(){
	std::cout << "Default constructor of MateriaSource is called" << std::endl;
	for (int i = 0; i < 4; i++) {
		materias[i] = NULL;
	}
}

// MateriaSource::MateriaSource(std::string const & name) {
// 	this->name = name;
// 	std::cout << "Parameter constructor of MateriaSource is called" << std::endl;
// 	for (int i = 0; i < 4; i++) {
// 		materias[i] = NULL;
// 	}
// }

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << "Copy constructor of MateriaSource is called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = NULL;
	}
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	std::cout << "Assignement operator of MateriaSource is called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (materias[i])
				delete materias[i];
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	std::cout << "Default destructor of MateriaSource is called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (materias[i])
			delete materias[i];
	}
}


void	MateriaSource::learnMateria(AMateria* m) {
	std::cout << "MateriaSource equip was called" << std::endl;
	if (!m)
		return ;

	int	i = 0;
	while (this->materias[i]) {
		i++;
	}
	if (i <= 3)
		this->materias[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	std::cout << "MateriaSource createMateria was called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (materias[i] && materias[i]->getType() == type)
			return (materias[i]->clone());
	}
	return (NULL);
}