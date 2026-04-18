#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <string>
# include <map>

class BitcoinExchange
{
	private :
		std::ifstream						_file;
		std::map<std::string, float>		_data;
	public :
		BitcoinExchange(void);
		BitcoinExchange(const std::string & s);
		BitcoinExchange(const BitcoinExchange & b);
		~BitcoinExchange(void);
		BitcoinExchange & operator=(const BitcoinExchange & b);
		void	parce_file(void);

};

#endif
