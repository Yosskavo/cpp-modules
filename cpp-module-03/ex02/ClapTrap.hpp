#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	protected :
		std::string name;
		unsigned int	hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;
	public  :
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &clap);
		virtual ~ClapTrap(void);
		ClapTrap & operator=(ClapTrap const &a);
		virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
