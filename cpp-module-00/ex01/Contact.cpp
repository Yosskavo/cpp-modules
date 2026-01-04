#include "Contact.hpp"

// ¿ here is setter for every member in class ?

void	Contact::setFirstName(std::string str)
{
	first_name = str;
}

void	Contact::setLastName(std::string str)
{
	last_name = str;
}

void	Contact::setNickName(std::string str)
{
	nickname = str;
}

void	Contact::setPhoneNumber(std::string str)
{
	phone_number = str;
}

void	Contact::setDarkestSecret(std::string str)
{
	darkest_secret = str;
}

// ¿ here is getter for every member in class ?

std::string	Contact::getFirstName(void)
{
	return (first_name);
};

std::string	Contact::getLastName(void)
{
	return (last_name);
}

std::string	Contact::getNickName(void)
{
	return (nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (phone_number);
}

std::string	Contact::getDarkestSecret(void)
{
	return (darkest_secret);
}
