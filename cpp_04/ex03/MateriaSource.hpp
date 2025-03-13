#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
//class AMateria;

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materias[4];
	public:
		MateriaSource();
		MateriaSource(std::string const & name);
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);

		~MateriaSource() ;
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif