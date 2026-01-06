#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Invalide number of argument ... please enter <filename> <string1> <string2>" << std::endl;
		return (1);
	}

	std::string y_file = av[1];
	std::string y_rplace = y_file + ".replace";
	std::string y_str_to_rplace = av[3];
	std::string y_str_to_find = av[2];
	std::string y_str;
	std::string y_read;
	size_t	y_endpos;
	size_t	y_startpos;

	std::ifstream y_filename(y_file.c_str());
	if (!(y_filename.is_open()))
	{
		std::cerr << "Invalide filename !" << std::endl;
		return (1);
	}
	std::ofstream y_filereplace(y_rplace.c_str());
	if (!(y_filereplace.is_open()))
	{
		std::cerr << "Faild to create " << y_rplace << std::endl;
		y_filename.close();
		return (1);
	}
	while (std::getline(y_filename, y_read))
	{
		y_startpos = 0;
		y_str = "";
		if (!(y_read.empty()))
			while ((y_endpos = y_read.find(y_str_to_find.c_str(), y_startpos)) != std::string::npos)
			{
				y_str += y_read.substr(y_startpos, y_endpos - y_startpos);
				y_str += y_str_to_rplace;
				y_startpos = y_endpos + y_str_to_find.length();
			}
		y_str += y_read.substr(y_startpos);
		y_filereplace << y_str;
		if (!(y_filename.eof()))
			y_filereplace << std::endl;
	}
	y_filereplace.close();
	y_filename.close();
}
