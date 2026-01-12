#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << "The Dog default constructor called!" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog), type(dog.type)
{
	std::cout << "The Dog copy constructor called!" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "the Dog destructor called!" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "The Dog assignement operator called!" << std::endl;
	if (this == &dog)
		return (*this);
	this->type = dog.type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Bark Bark!" << std::endl;
}

void Dog::setType(const std::string & p_name)
{
	this->type = p_name;
}

std::string Dog::getType(void) const
{
	return (this->type);
}
