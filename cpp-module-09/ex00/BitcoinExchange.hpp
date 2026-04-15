#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>

class BitcoinExchange
{
	private :
		std::ifstream	file;
	public :
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange & b);
		~BitcoinExchange(void);
		BitcoinExchange & operator=(const BitcoinExchange & b);

};

#endif
