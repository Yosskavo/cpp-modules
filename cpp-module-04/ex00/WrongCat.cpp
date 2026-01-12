#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "The WrongCat default constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal(cat), type(cat.type)
{
	std::cout << "The WrongCat copy constructor called!" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "the WrongCat destructor called!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &cat)
{
	std::cout << "The WrongCat assignement operator called!" << std::endl;
	if (this == &cat)
		return (*this);
	this->type = cat.type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "meao meao!" << std::endl;
}

void WrongCat::setType(const std::string & p_name)
{
	this->type = p_name;
}

std::string WrongCat::getType(void) const
{
	return (this->type);
}
