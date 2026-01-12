#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : type("")
{
	std::cout << "The Animal default constroctur called !" << std::endl;
}

Animal::Animal(const std::string &p_name) : type(p_name)
{
	std::cout << "The Animal " +this->type+ " constroctur called !" << std::endl;
}

Animal::Animal(const Animal &animal) : type(animal.type)
{
	std::cout << "The Animal " +this->type+ " copy constroctur called !" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "The Animal " +this->type+ " destructors called !" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	if (&animal != this)
		this->type = animal.type;
	std::cout << "The Animal " +this->type+ " copy assignement constroctur called !" << std::endl;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::setType(const std::string &p_name)
{
	this->type = p_name;
}

void Animal::makeSound(void) const
{
	std::cout << "sound of animal!" << std::endl;
}
