#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : name("")
{
	this->attack_damage = FragTrap::attack_damage;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	this->attack_damage = FragTrap::attack_damage;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	std::cout << "DiamondTrap " +this->name+ " copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamond) : ClapTrap(diamond.name + "_clap_name"), ScavTrap(diamond.name), FragTrap(name), name(diamond.name)
{
	this->attack_damage = diamond.attack_damage;
	this->energy_points = diamond.energy_points;
	this->hit_points = diamond.hit_points;
	std::cout << "DiamondTrap " +this->name+ " copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap & diamond)
{
	if (this != &diamond)
	{
		this->name = diamond.name;
		this->attack_damage = diamond.attack_damage;
		this->energy_points = diamond.energy_points;
		this->hit_points = diamond.hit_points;
	}
	std::cout << "DiamondTrap " +this->name+ " copy assignement constructor called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " +this->name+ " deconstructor" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " +this->name+ " its name in ClapTrap " +this->ClapTrap::name << std::endl;
}

