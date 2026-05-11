#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <float.h>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <iomanip>

void char_value(char value)
{
	if (value < 31 || value > 126)
	{
		std::cout << "char : Non displayable" << std::endl;
	}
	else {
		std::cout << "char : " << static_cast<char>(value) << std::endl;
	}
	std::cout << "int : " << static_cast<int>(value)   << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void double_value(double value)
{
	if (value > INT_MAX || value < INT_MIN || std::isnan(value) || std::isinf(value))
	{
		std::cout << "int : Impossible" << std::endl;
	}
	else {
		std::cout << "int : " << static_cast<int>(value) << std::endl;
	}
	if (value > CHAR_MAX || value < CHAR_MIN || std::isnan(value) || std::isinf(value))
	{
		std::cout << "char : Impossible" << std::endl;
	}
	else {

		if (value < 31 || value > 126)
		{
			std::cout << "char : Non displayable" << std::endl;
		}
		else {
			std::cout << "char : " << static_cast<char>(value) << std::endl;
		}
	}
	if (value > FLT_MAX || value < FLT_MIN)
	{
		std::cout << "float : Impossible" << std::endl;
	}
	else {
		std::cout << "float : " <<  std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	}
	std::cout << "double : " << std::fixed << std::setprecision(1) <<value << std::endl;
}

void float_value(float value)
{
	if (value > INT_MAX || value < INT_MIN || std::isnan(value) || std::isinf(value))
	{
		std::cout << "int : Impossible" << std::endl;
	}
	else {
		std::cout << "int : " << static_cast<int>(value) << std::endl;
	}
	if (value > CHAR_MAX || value < CHAR_MIN || std::isnan(value) || std::isinf(value))
	{
		std::cout << "char : Impossible" << std::endl;
	}
	else {

		if (value < 31 || value > 126)
		{
			std::cout << "char : Non displayable" << std::endl;
		}
		else {
			std::cout << "char : " << static_cast<char>(value) << std::endl;
		}
	}
	std::cout << "float : " <<  std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) <<value << std::endl;
}

void int_value(long value)
{
	if (value > INT_MAX || value < INT_MIN || std::isnan(value) || std::isinf(value))
	{
		std::cout << "int : Impossible" << std::endl;
	}
	else {
		std::cout << "int : " << static_cast<int>(value) << std::endl;
	}
	if (value > CHAR_MAX || value < CHAR_MIN || std::isnan(value) || std::isinf(value))
	{
		std::cout << "char : Impossible" << std::endl;
	}
	else {

		if (value < 31 || value > 126)
		{
			std::cout << "char : Non displayable" << std::endl;
		}
		else {
			std::cout << "char : " << static_cast<char>(value) << std::endl;
		}
	}
	if (value > FLT_MAX || value < FLT_MIN)
	{
		std::cout << "float : Impossible" << std::endl;
	}
	else {
		std::cout << "float : " <<  std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	}
	std::cout << "double : " << std::fixed << std::setprecision(1) <<value << std::endl;
}

void float_handle(const char *s)
{
	double value;
	char *c;

	value = std::strtod(s, &c);
	if ((*c == 'f' && std::strlen(c) > 1) || (*c != '\0' && *c != 'f'))
	{
		std::cout << "Invalide argument : it containe invalide characters" << std::endl;
		return ;
	}
	else if (*c == 'f')
	{
		float_value(value);
		return ;
	}
	else 
	{
		double_value(value);
	}
}

void int_handle(const char *s)
{
	char *c;
	long value = std::strtol(s, &c, 10);

	if (*c != '\0')
	{
		std::cout << "Invalide character" << std::endl;
		return ;
	}
	int_value(value);
}

void psedu_handle(const std::string s)
{
	char *c;

	if (s == "-inff" || s == "+inff" || s == "nanf")
	{
		float_value(std::strtod(s.c_str(), &c));
	}
	else if (s == "-inf" || s == "+inf" || s == "nan")
	{
		double_value(std::strtod(s.c_str(), &c));
	}
	else
	{
		std::cout << "Invalide string : isn't psedu, char, int, float, double" << std::endl;
	}
}

void ScalarConverter::Converter(const char * s)
{
	if (std::strlen(s) == 1 && !std::isdigit(*s))
	{
		char_value(*s);
	}
	else {
		for (int i = 0; s[i]; i++)
		{
			if (s[i] == '.')
			{
				float_handle(s);
				return ; 
			}
			else if (!std::isdigit(s[i]) && !(s[i] == '+' || s[i] == '-'))
			{
				psedu_handle(s);
				return ;
			}
		}
		int_handle(s);
	}
}


ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::~ScalarConverter(void)
{
}


ScalarConverter::ScalarConverter(const ScalarConverter & s)
{
	(void)s;
}


ScalarConverter & ScalarConverter::operator=(const ScalarConverter & s)
{
	(void)s;
	return (*this);
}

