#include "RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <stdexcept>

typedef enum e_tocken {
	NUMBER,
	ADD,
	MULTI,
	SUBS,
	DEVI,
	SPACE,
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

t_tocken	ft_tocken(std::string::const_iterator &it)
{
	if (*it == ' ')
		return (SPACE);
	if (*it == '+' || *it == '-')
	{
		it++;
		if (std::isdigit(*it))
			return (it--, NUMBER);
		if (*it == ' ' || *it == '\0')
		{
			*it--;
			if (*it == '+')
				return (ADD);
			return (SUBS);
		}
		return (ERROR);
	}
	if (*it == '*')
		return (MULTI);
	if (*it == '/')
		return (DEVI);
	if (std::isdigit(*it))
		return (NUMBER);
	return (ERROR);
}

short ft_convert(std::string::const_iterator & it)
{
	short value;

	value = 1;
	if (*it == '+' || *it == '-')
	{
		if (*it == '-')
			value *= -1;
		it++;
	}
	value *= (*it - 48);
	return (value);
}

int	RPN::calculat_RPN(const std::string &s)
{
	int			value;
	int			tmp_one;
	int			tmp_two;
	t_tocken	tocken;

	value = 0;
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++)
	{
		tocken = ft_tocken(it);
		switch (tocken)
		{
			case NUMBER :
				this->_stack.push(ft_convert(it));
				break;
			case ADD :
				if (this->_stack.size() < 2)
					throw std::runtime_error("you need numbers to do this operator");
				tmp_one = this->_stack.top();
				this->_stack.pop();
				tmp_two = this->_stack.top();
				this->_stack.pop();
				this->_stack.push(tmp_two + tmp_one);
				break;
			case MULTI :
				if (this->_stack.size() < 2)
					throw std::runtime_error("you need numbers to do this operator");
				tmp_one = this->_stack.top();
				this->_stack.pop();
				tmp_two = this->_stack.top();
				this->_stack.pop();
				this->_stack.push(tmp_two * tmp_one);
				break;
			case SUBS :
				if (this->_stack.size() < 2)
					throw std::runtime_error("you need numbers to do this operator");
				tmp_one = this->_stack.top();
				this->_stack.pop();
				tmp_two = this->_stack.top();
				this->_stack.pop();
				this->_stack.push(tmp_two - tmp_one);
				break ;
			case DEVI :
				if (this->_stack.size() < 2)
					throw std::runtime_error("you need numbers to do this operator");
				tmp_one = this->_stack.top();
				this->_stack.pop();
				tmp_two = this->_stack.top();
				this->_stack.pop();
				if (!tmp_one)
					throw std::runtime_error("you can't devide this numbers on 0");
				this->_stack.push(tmp_two / tmp_one);
				break ;
			case SPACE :
				break ;
			case ERROR :
				throw std::runtime_error("Invalide character");
				break ;
		}
		if (tocken != SPACE && (*(++it) != ' ' && *it != '\0') )
		{
			throw std::runtime_error("Invalide character");
		}
		if (*it == '\0')
			it--;
	}
	if (this->_stack.size() != 1)
	{
		throw std::runtime_error("less operator's than the numbers afforded");
	}
	value = this->_stack.top();
	this->_stack.pop();
	return (value);
}

