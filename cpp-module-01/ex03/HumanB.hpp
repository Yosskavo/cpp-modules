#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private :
		std::string name;
		Weapon *weapon;
	public :
		HumanB(std::string str);
		void setWeapon(Weapon &type);
		void attack(void);
};

#endif
