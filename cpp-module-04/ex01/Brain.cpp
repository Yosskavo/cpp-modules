#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "Brain default constructor called !" << std::endl;
}

Brain::Brain(const std::string (&p_name)[100])
{
	std::cout << "Brain copy paramter called !" << std::endl;
	for (int i = 0; 0 < 100; i++)
	{
		this->ideas[i] = p_name[i];
	}
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain copy assignement called !" << std::endl;
	this->operator=(brain);
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain copy operator called !" << std::endl;
	if (this == &brain)
		return (*this);
	for (int i = 0; 0 < 100; i++)
	{
		this->ideas[i] = brain.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destroctur called !" << std::endl;
}
