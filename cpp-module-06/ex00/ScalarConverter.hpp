#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <exception>

class ScalarConverter
{
	private :
		ScalarConverter(void);
	public :
		static void Converter(const char * name);
		class InvalideElementsInString : public std::exception
		{
			virtual const char * what() const throw()
			{
				return "Invalide element's in string";
			}
		};
};

#endif
