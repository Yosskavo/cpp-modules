#include <iostream>

int main()
{
	std::string str;

	std::cout << "Welcom to the PhoneBook\n";
	std::cout << "Inter a command [ADD, SEARCH, EXIT] : ";
	while (std::getline(std::cin, str))
	{
		if (str == "EXIT")
			return (0);
		else if (str == "SEARCH")
			continue ;
		// code here for searching
		else if (str == "ADD")
			continue ;
		// another line of code for adding ppl
		else
			std::cout << "Erorr : Unknown command !";
		std::cout << "Inter a command [ADD, SEARCH, EXIT] : ";
	}
	return (1);
}
