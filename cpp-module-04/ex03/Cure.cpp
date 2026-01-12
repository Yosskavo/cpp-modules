#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(const Cure &cure) : AMateria(cure)
{
}

Cure &Cure::operator=(const Cure &cure)
{
	if (this == &cure)
		return (*this);
	this->_type = cure._type;
	return (*this);
}

Cure::~Cure(void)
{
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure());
}
