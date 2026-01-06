#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *arr = new(std::nothrow) Zombie[N];
	if (arr == NULL)
		return (NULL);
	for (int i = 0; i < N ; i++)
	{
		arr[i].setName(name);
	}
	return (arr);
}

