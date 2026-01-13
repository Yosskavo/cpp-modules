#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private :
		AMateria *materias[4];
	public :
		MateriaSource(void);
		MateriaSource(const MateriaSource &materia);
		~MateriaSource(void);
		MateriaSource & operator=(const MateriaSource &materia);
		void learnMateria(AMateria *materia);
		AMateria *createMateria(std::string const & type);
};

#endif
