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

		void	parce_file(void);
		float	search_date(const std::string & s);
	public :
		BitcoinExchange(void);
		BitcoinExchange(const std::string & s);
		BitcoinExchange(const BitcoinExchange & b);
		~BitcoinExchange(void);
		BitcoinExchange & operator=(const BitcoinExchange & b);
		void			calculate_value(const std::string &str);
};

#endif
