#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & b)
{
	this->operator=(b);
}


BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & b)
{
	if (&b != this)
	{
	}
	return (*this);
}

