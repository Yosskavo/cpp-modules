#include "AMateria.hpp"

AMateria::AMateria(void) : _type("")
{
}

AMateria::AMateria(const AMateria & other) : _type(other._type)
{
}

AMateria::AMateria(const std::string &type) : _type(type)
{
}

AMateria::~AMateria(void)
{
}

void AMateria::setType(const std::string &type)
{
	this->_type = type;
}

const std::string & AMateria::getType(void) const
{
	return (this->_type);
}


void use(ICharacter &target);
