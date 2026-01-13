#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private :
		AMateria *_inventory[4];
		AMateria **_array;
		std::string _name;
		int	_count;
		void amateria_garbage(int a_new);
	public :
		Character(void);
		Character(const Character & character);
		Character(const std::string &name);
		Character &operator=(const Character & character);
		~Character(void);
		std::string const &getName(void) const;
		void equip(AMateria *m);
		void unequip(int indx);
		void use(int indx, ICharacter & target);
};

#endif
