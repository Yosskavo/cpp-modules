#include "RPN.hpp"
#include <cctype>

typedef enum e_tocken {
	SPACE,
	NUMBER,
	ADD,
	MULTI,
	SUBS,
	DEVI,
	ERROR
} t_tocken;

RPN::RPN(void)
{
}

RPN::~RPN(void)
{
}

RPN::RPN(const RPN &r)
{
	this->operator=(r);
}

RPN & RPN::operator=(const RPN& r)
{
	if (&r == this)
	{
	}
	return (*this);
}

t_tocken	ft_tocken(char c)
{
	if (c == ' ')
		return (SPACE);
	if (c == '+')
		return (ADD);
	if (c == '-')
		return (SUBS);
	if (c == '*')
		return (MULTI);
	if (c == '/')
		return (DEVI);
	if (std::isdigit(c))
		return (NUMBER);
	return (ERROR);
}

int	RPN::calculat_RPN(const std::string &s)
{
	int			value;
	t_tocken	tocken;

	value = 0;
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++)
	{
		tocken = ft_tocken(*it);
		if (*it == SPACE)
		{
			it++;
			tocken = ft_tocken(*it);
		}
		if (tocken == ERROR)
		{
			throw std::runtime_error("");
		}
	}
	return (value);
}


