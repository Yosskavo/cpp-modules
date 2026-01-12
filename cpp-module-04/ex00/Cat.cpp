#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal(), type("Cat")
{
	std::cout << "The Cat default constructor called!" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat), type(cat.type)
{
	std::cout << "The Cat copy constructor called!" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "the Cat destructor called!" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "The Cat assignement operator called!" << std::endl;
	if (this == &cat)
		return (*this);
	this->type = cat.type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "meao meao!" << std::endl;
}

std::string Cat::getType(void) const
{
	return (this->type);
}

void Cat::setType(const std::string & p_name)
{
	this->type = p_name;
}
