#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctype.h>

void PhoneBook::RefrechIndex(bool flag)
{
	if (!flag)
	{
		saved_contact = 0;
		index = 0;
	}
	if (flag)
	{
		if (saved_contact < 8)
			saved_contact++;
		index++;
	}
	if (index == 8)
		index = 0;
}

static void	show_fild(std::string fild)
{
	if (fild.length() < 10)
		std::cout << std::setw(10) << fild;
	else if (fild.length() == 10)
		std::cout << fild;
	else
		std::cout << fild.substr(0, 9) << ".";
	std::cout << "|";
}

static void show_all_filds(Contact contact)
{
	std::cout << "Here the full information for the contact you searched for" << std::endl;
	std::cout << std::left << std::setw(15) << "First Name" << ": " << contact.getFirstName() << std::endl;
	std::cout << std::left << std::setw(15) << "Last Name" << ": " << contact.getLastName() << std::endl;
	std::cout << std::left << std::setw(15) << "Nick Name" <<  ": " << contact.getNickName() << std::endl;
	std::cout << std::left << std::setw(15) << "Phone Number" << ": " << contact.getPhoneNumber() << std::endl;
	std::cout << std::left << std::setw(15) << "Darkest secret" << ": " << contact.getDarkestSecret() << std::endl;
}

bool PhoneBook::getContact(void)
{
	int				position;
	std::string		str_pos;

	if (!saved_contact)
	{
		std::cout << "The contact's are empty ! enter a contact first to use this option !" << std::endl;
		return (true);
	}
	std::cout << "Index     |First Name|Last Name |Nickname  |" << std::endl;
	for (short i = 0; i < saved_contact; i++)
	{
		std::cout << (i + 1) << "         |";
		show_fild(contact[i].getFirstName());
		show_fild(contact[i].getLastName());
		show_fild(contact[i].getNickName());
		std::cout << std::endl;
	}
	while(1) 
	{
		std::cout << "Please enter the index of the contact to show its information : ";
		if (!(std::getline(std::cin, str_pos)))
		{
			return (false);
		}
		position = atoi(str_pos.c_str());
		if (position > 0 && position <= saved_contact)
			break ;
		std::cout << "Invalide position re-";
	}
	show_all_filds(contact[position - 1]);
	return (true);
}

static bool ft_check_input(std::string input)
{
	if (input.empty())
		return (0);
	for (int i = 0; input[i] ; i++)
	{
		if (!isspace(input[i]))
			return (1);
	}
	return (0);
}

static std::string	ft_getline_helper(std::string message)
{
	std::string tmp;

	if (std::cin.eof() || std::cin.fail())
		return ("");
	while (1)
	{
		std::cout << "enter the " << message << " of the contact : ";
		if (!(std::getline(std::cin, tmp)))
			break ;
		if (std::cin.eof() || std::cin.fail())
			return ("");
		if (ft_check_input(tmp))
			return (tmp);
		std::cout << "Invalide input please re-";
	}
	return ("");
}

static bool check_phone_number(std::string phone)
{
	for (size_t i = 0; i < phone.length(); i++)
	{
		if (!isdigit(phone[i]))
		return (false);
	}
	return (true);
}

bool PhoneBook::setContact(void)
{
	std::string	tmp;

	std::cout << "Please inter the next information !" << std::endl;
	tmp = ft_getline_helper("first name");
	if (tmp == "")
		return (false);
	contact[index].setFirstName(tmp);
	tmp = ft_getline_helper("last name");
	if (tmp == "")
		return (false);
	contact[index].setLastName(tmp);
	tmp = ft_getline_helper("nickname");
	if (tmp == "")
		return (false);
	contact[index].setNickName(tmp);
	tmp = ft_getline_helper("darkest secret");
	if (tmp == "")
		return (false);
	contact[index].setDarkestSecret(tmp);
	while (1)
	{
		tmp = ft_getline_helper("phone number");
		if (tmp == "")
			return (false);
		if (check_phone_number(tmp))
			break ;
		std::cout << "the phone number must contain digits only" << std::endl;
		std::cout << "Please re-";
	}
	contact[index].setPhoneNumber(tmp);
	RefrechIndex(true);
	return (true);
}
