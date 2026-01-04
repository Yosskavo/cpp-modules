#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	PhoneBook book;
	std::string argument;

	std::cout << "Welcom to the PhoneBook :)" << std::endl;
	book.RefrechIndex(false);
	while (1)
	{
		std::cout << "Chose one of this argument [ADD/SEARCH/EXIT] : ";
		if (!std::getline(std::cin, argument))
			break ;
		if (argument == "EXIT")
		{
			std::cout << "Thank you for using the PhoneBook and goodbye :)" << std::endl;
			break ;
		}
		else if (argument == "SEARCH")
		{
			if (!(book.getContact()))
				break ;
		}
		else if (argument == "ADD")
		{
			if (!(book.setContact()))
				break ;
		}
		else
			std::cout << "Invalide option ! please re-";
	}
	if (std::cin.eof())
	{
		std::cout << "\nAn end of file detected while trying to read input form user" << std::endl;
		return (1);
	}
	if (std::cin.fail())
	{
		std::cout << "Input faild while trying to read input form user" << std::endl;
		return (2);
	}
	return (0);
}
