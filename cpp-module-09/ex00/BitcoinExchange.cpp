#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : _file("data.csv")
{
	if (this->_file.fail())
	{
		throw ;
	}
	this->parce_file();
}

void BitcoinExchange::parce_file(void)
{
	std::string s;

	std::getline(this->_file, s, '\n');
	// if ()
	// {
	//
	// }
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
	}
	return (*this);
}

