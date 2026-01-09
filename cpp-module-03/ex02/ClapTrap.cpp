#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : name(""), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &p_name) : name(p_name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " +this->name+ " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & clap) : name(clap.name), hit_points(clap.hit_points), energy_points(clap.energy_points), attack_damage(clap.attack_damage)
{
	std::cout << "ClapTrap " +this->name+ " copy constructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & clap)
{
	if (&clap != this)
	{
		this->energy_points = clap.energy_points;
		this->name = clap.name;
		this->hit_points = clap.hit_points;
		this->attack_damage = clap.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " +this->name+ " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energy_points)
	{
		std::cout << "ClapTrap " +this->name +" attacks " +target+ " , cousing " << this->attack_damage << " points of damage!"<< std::endl;
		this->energy_points--;
	}
	else
	{
		std::cout << "ClapTrap " +this->name+ " has no enough energy points to do an action" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!amount)
	{
		std::cout << "ClapTrap " +this->name+ " Toke no damage!" << std::endl;
	}
	else if (this->hit_points)
	{
		std::cout << "ClapTrap " +this->name+ " Toke " << amount << " amount of damage!" << std::endl;
		if (this->hit_points > amount)
			this->hit_points -= amount;
		else
			this->hit_points = 0;
	}
	else 
	{
		std::cout << "ClapTrap " +this->name+ " is already dead!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points)
	{
		this->hit_points += amount;
		this->energy_points--;
		std::cout << "ClapTrap " +this->name+ " got this " << amount << " amount of hit point and now hist current hit points " << this->hit_points << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " +this->name+ " has no enough energy points to do an action" << std::endl;
	}
}

