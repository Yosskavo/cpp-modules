#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : type("")
{
	std::cout << "The WrongAnimal default constroctur called !" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &p_name) : type(p_name)
{
	std::cout << "The WrongAnimal " +this->type+ " constroctur called !" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal) : type(animal.type)
{
	std::cout << "The WrongAnimal " +this->type+ " copy constroctur called !" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "The WrongAnimal " +this->type+ " destructors called !" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	if (&animal != this)
		this->type = animal.type;
	std::cout << "The WrongAnimal " +this->type+ " copy assignement constroctur called !" << std::endl;
	return (*this);
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

void WrongAnimal::setType(const std::string &p_name)
{
	this->type = p_name;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "sound of animal!" << std::endl;
}

