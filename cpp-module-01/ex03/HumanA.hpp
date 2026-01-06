#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private :
		std::string name;
		Weapon weapon;
	public :
		HumanA(Weapon &weapon);
		HumanA(std::string, Weapon &weapon);
		void attack(void);
};

#endif
