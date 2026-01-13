#include "AMateria.hpp"

AMateria::AMateria(void) : _type("")
{
}

AMateria::AMateria(const AMateria & other)
{
	this->operator=(other);
}

AMateria::AMateria(const std::string &type) : _type(type)
{
}

AMateria::~AMateria(void)
{
}

AMateria &AMateria::operator=(const AMateria & materia)
{
	// if (this == &materia)
	// 	return (*this);
	// this->_type = materia._type;
	(void)materia;
	return (*this);
}

void AMateria::setType(const std::string &type)
{
	this->_type = type;
}

const std::string & AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::use(ICharacter & target)
{
	(void)target;
}
