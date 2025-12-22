#include "PhoneBook.hpp"
#include <iostream>

int check_input(std::string str)
{
	for (int i = 0; i < str.strlen(); i++)
	{

	}
}

std::string	get_string(std::string message)
{
	std::string	tmp;

	std::cout << message << std::endl;
	while (std::getline(std::cin, tmp))
	{
		if (!check_input(tmp))
			return (tmp);
		std::cout << "Please re-" +message << std::endl;
	}
	return (tmp);
}

int add_contact(PhoneBook phone)
{
	std::string	tmp;

	tmp = get_string("inter first name");
	if (std::cin.eof() || std::cin.fail())
		return (0);
	set_first_name(tmp);
	tmp = get_string("inter last name");
	if (std::cin.eof() || std::cin.fail())
		return (0);
	set_last_name(tmp);
	tmp = get_string("inter nickname");
	if (std::cin.eof() || std::cin.fail())
		return (0);
	set_nickname(tmp);
	tmp = get_string("inter darkest secret");
	if (std::cin.eof() || std::cin.fail())
		return (0);
	set_darkest_secret(tmp);
	tmp = get_string("inter phone number");
	if (std::cin.eof() || std::cin.fail())
		return (0);
	set_phone_number(tmp);
	return (1);
}
