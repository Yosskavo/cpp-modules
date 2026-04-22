#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(void) : _file("data.csv")
{
	if (this->_file.fail())
	{
		throw std::runtime_error("fail to open the file 'data.csv'");
	}
	this->parce_file();
}


BitcoinExchange::BitcoinExchange(const std::string & filename)
{
	std::string n = filename.substr(filename.find(".") + 1);

	if (n != "csv")
	{
		throw std::runtime_error("Invalide extantion filename '." +n+ "' (Expected '.csv')" );
	}
	if (this->_file.fail())
	{
		throw std::runtime_error("fail to open the file '" +filename+ "'");
	}
	this->parce_file();
}

std::string  ft_checker_date(std::string str)
{
	int	y, m, d;
	int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char c;

	if (sscanf(str.c_str(), "%d-%d-%d%c", &y, &m, &d, &c) != 3)
	{
		throw std::runtime_error("this '" +str+ "' is an invalide date");
	}
	if (m > 12 || m == 0)
	{
		throw std::runtime_error("this '" +str+ "' have an invalide month");
	}
	if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
	{
		month[1] = 29;
	}
	if (d == 0 || d > month[m - 1])
	{
		throw std::runtime_error("this '" +str+ "' have an invalide day");
	}
	return (str);
}

float		ft_checker_value(std::string str, bool flag)
{
	float		value;
	char		*c;

	if (str.empty())
	{
		throw std::runtime_error("the value is empty");
	}
	value = std::strtod(str.c_str(), &c);
	if (*c != '\n' && *c != '\0')
	{
		throw std::runtime_error("this value '" +str+ "' invalid");
	}
	if (flag && (value < 0 || value > 1000))
	{
		throw std::runtime_error("this value '" +str+ "' is out of range (0 < v < 1000)");
	}
	return (value);
}

void BitcoinExchange::parce_file(void)
{
	std::string		s;
	std::string		tmp_s;
	float			v;
	size_t			pos;

	std::getline(this->_file, s, '\n');
	if (this->_file.fail() && !this->_file.eof())
	{
		throw std::runtime_error("fail to read the file");
	}
	if (s == "date,exchange_rate")
	{
		std::getline(this->_file, s, '\n');
		if (this->_file.fail() && !this->_file.eof())
		{
			throw std::runtime_error("fail to read the file");
		}
	}
	if (this->_file.eof())
	{
		throw std::runtime_error("The datebase is empty");
	}
	do 
	{
		try
		{
			pos = s.find(",");
			if (pos == std::string::npos)
			{
				throw std::runtime_error("this line '" +s+ "' doesn't follow the formatte 'date,exchange_rate'");
			}
			tmp_s = ft_checker_date(s.substr(0, pos));
			v = ft_checker_value(s.substr(pos + 1), 0);
			this->_data[tmp_s] = v;
		}
		catch(const std::exception & e)
		{
			std::cout << "Error accurted in the data base (line : '" +s+ "') : " << e.what() << std::endl;
		}
	} while(std::getline(this->_file, s, '\n'));
	if (this->_file.fail() && !this->_file.eof())
	{
		throw std::runtime_error("fail to read the file");
	}
	if (this->_data.empty())
	{
		throw std::runtime_error("The datebase is empty");
	}
}

float BitcoinExchange::search_date(const std::string & s)
{
	float	value;
	int			i;

	value = 0;
	i = 0;
	if (this->_data.count(s) != 0)
	{
		return (this->_data[s]);
	}
	for (std::map<std::string, float>::iterator it = this->_data.begin(); it != this->_data.end(); it++)
	{
		if (s < it->first)
		{
			if (i != 0)
				it--;
			value = it->second;
			break ;
		}
		if (++it == this->_data.end())
		{
			it--;
			value = it->second; 
		}
		else
		{
			it--;
		}
		i++;
	}
	return (value);
}

void	BitcoinExchange::calculate_value(const std::string & str)
{
	std::ifstream bit_file(str.c_str());

	if (bit_file.fail())
	{
		throw std::runtime_error("Failed to open the file");
	}

	std::string		s;
	std::string		tmp_s;
	float			v;
	size_t				pos;

	std::getline(bit_file, s, '\n');
	if (bit_file.fail() && !bit_file.eof())
	{
		throw std::runtime_error("fail to read the file");
	}
	if (s == "date | value")
	{
		std::getline(bit_file, s, '\n');
		if (bit_file.fail())
		{
			throw std::runtime_error("fail to read the file");
		}
	}
	if (bit_file.eof())
	{
		throw std::runtime_error("the file is empty");
	}
	do
	{
		try
		{
			pos = s.find(" | ");
			if (pos == std::string::npos)
			{
				throw std::runtime_error("this line '" +s+ "' doesn't follow the formatte 'date | value'");
			}
			tmp_s = ft_checker_date(s.substr(0, pos));
			v = ft_checker_value(s.substr(pos + 3), 1);
			std::cout << tmp_s + " => " << v << " = " << (float)(v) * this->search_date(tmp_s) << std::endl;
		}
		catch(const std::exception & e)
		{
			std::cout << "Error accurted in the data base (line : '" +s+ "') : " << e.what() << std::endl;
		}
	}
	while(std::getline(bit_file, s, '\n'));
	if (bit_file.fail() && !bit_file.eof())
	{
		throw std::runtime_error("fail to read the file");
	}
	bit_file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & b)
{
	this->operator=(b);
}

BitcoinExchange::~BitcoinExchange(void)
{
	this->_file.close();
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & b)
{
	if (&b != this)
	{
		this->_data = b._data;
	}
	return (*this);
}

