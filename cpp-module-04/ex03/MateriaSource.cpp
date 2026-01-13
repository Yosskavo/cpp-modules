#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->materias[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource & materia)
{
	this->operator=(materia);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materia)
{
	if (this == &materia)
		return (*this);
	int c = 0;
	for (int i = 0; i < 4; i++)
	{
		if (materia.materias[i])
		{
			this->materias[c] = materia.materias[i]->clone();
			c++;
		}	
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!(this->materias[i]))
		{
			this->materias[i] = materia;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])
		{
			if (this->materias[i]->getType() == type)
				return (this->materias[i]->clone());
		}
	}
	return (0);
}
