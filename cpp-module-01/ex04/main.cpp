#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	std::string y_file = av[1];
	std::string y_rplace = y_file + ".replace";

	if (ac != 4)
	{
		std::cout << "Invalide number of argument ... please enter <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	std::ifstream y_filename(y_file);
	if (!(y_filename.is_open()))
	{
		std::cout << "Invalide filename !" << std::endl;
		return (1);
	}
	std::ofstream y_filereplace(y_rplace);
	if (!(y_filereplace.is_open()))
	{
		std::cout << "Faild to create " << y_rplace << std::endl;
		return (1);
	}
}
