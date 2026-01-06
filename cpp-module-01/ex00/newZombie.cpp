#include "Zombie.hpp" 
#include <new>

Zombie	*newZombie(std::string name)
{
	Zombie *obj = new(std::nothrow) Zombie;

	if (!obj)
		return (NULL);
	obj->setName(name);
	return (obj);
}
