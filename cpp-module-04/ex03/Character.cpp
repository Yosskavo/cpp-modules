#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void) : _name(""), _count(1)
{
	_array = new AMateria*;
	*_array = NULL;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(const Character & character)
{
	this->operator=(character);
}

Character::Character(const std::string & name) : _name(name), _count(1)
{
	_array = new AMateria*;
	*_array = NULL;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

void Character::amateria_garbage(int a_new)
{
	AMateria **array = new AMateria*[this->_count + a_new];
	
	int c = 0;
	for (int i = 0; i < this->_count; i++)
	{
		array[c] = this->_array[i];
		c++;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			array[c] = this->_inventory[i];
			c++;
		}
	}
	array[c] = NULL;
	delete this->_array;
	this->_array = array;
	this->_count += a_new;
}

Character &Character::operator=(const Character &character)
{
	if (this == &character)
		return (*this);
	if (!(this->_array))
	{
		this->_array = new AMateria*;
		*(this->_array) = NULL;
	}
	int c = 0;
	for (int i = 0; i < 4; i++)
	{
		if (character._inventory[i])
		{
			this->_inventory[i] = character._inventory[i]->clone();
			c++;
		}
	}
	amateria_garbage(c);
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
	}
	for (int i = 0; i < _count; i++)
	{
		delete this->_array[i];
	}
	delete this->_array;
}

const std::string & Character::getName(void) const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!(this->_inventory[i]))
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int indx)
{
	if (indx < 0 || indx > 3)
		return ;
	if (this->_inventory[indx])
		this->_inventory[indx] = NULL;
}

void Character::use(int indx, ICharacter & target)
{
	if (indx < 0 || indx > 3)
		return ;
	if (this->_inventory[indx])
		this->_inventory[indx]->use(target);
}
