#include "Ice.hpp"
#include <iostream>
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
}

Ice::~Ice(void)
{
}

Ice &Ice::operator=(const Ice &ice)
{
	if (this == &ice)
		return (*this);
	this->_type = ice._type;
	return (*this);
}

AMateria *Ice::clone(void) const
{
	return (new Ice());
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
