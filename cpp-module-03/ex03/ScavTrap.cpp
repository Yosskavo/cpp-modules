#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap Default constructor called!" << std::endl; 
}

ScavTrap::ScavTrap(const std::string & name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " +this->name+ " constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scav) : ClapTrap(scav)
{
	std::cout << "ScavTrap " +this->name+ " copy constructor called!" << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &scav)
{
	if (this != &scav)
	{
		this->name = scav.name;
		this->hit_points = scav.hit_points;
		this->energy_points = scav.energy_points;
		this->attack_damage = scav.attack_damage;
	}
	std::cout << "ScavTrap " +this->name+ " copy assignement operator called!" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " +this->name+ " the destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->energy_points)
	{
		std::cout << "ScavTrap " +this->name +" attacks " +target+ " , cousing " << this->attack_damage << " points of damage!"<< std::endl;
		this->energy_points--;
	}
	else
	{
		std::cout << "ScavTrap " +this->name+ " has no enough energy points to do an action" << std::endl;
	}
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " +this->name+ " is now in Gate keeper mode!" << std::endl;
}

