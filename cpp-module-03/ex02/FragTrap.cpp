#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap default constructor called!" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " +this->name+ " constructor called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &frag) : ClapTrap(frag)
{
	std::cout << "FragTrap " +this->name+ " copy constructor called!" << std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap &frag)
{
	if (this != &frag)
	{
		this->name = frag.name;
		this->hit_points = frag.hit_points;
		this->energy_points = frag.energy_points;
		this->attack_damage = frag.attack_damage;
	}
	std::cout << "FragTrap " +this->name+ " copy assignement called!" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " +this->name+ " deconstructor called!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High Five Guys!" << std::endl;
}
