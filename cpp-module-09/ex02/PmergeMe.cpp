#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>
#include <stdexcept>
#include <iostream>

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe & p)
{
	this->operator=(p);
}

void	PmergeMe::InsertElements(const char **av)
{
	long		tmp;
	char	*c;

	for (int i = 0; av[i]; i++)
	{
		tmp = std::strtol(av[i], &c, 10);
		if (tmp > INT_MAX || tmp < 0)
		{
			throw std::runtime_error("Invalide element : you should inter numbers in range (0 < v < INT_MAX)");
		}
		if (*c != '\0')
		{
			throw std::runtime_error("Invalide element inside the gaven numbers");
		}
		this->_vector.push_back(tmp);
		this->_deque.push_back(tmp);
	}
}

void	PmergeMe::print_it(void)
{
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++)
	{
		std::cout << *it  << " ";
	}
}

void	PmergeMe::SortVector(void)
{
	std::vector<std::pair<int, int> >		tmpv;
	int										tmpi;
	int										tmp;

	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++)
	{
		tmpi = *it;
		it++;
		if (it != this->_vector.end())
		{
			tmpv.push_back(std::make_pair(tmpi, *it));
		}
		else {
			tmpv.push_back(std::make_pair(tmpi, -1));
			it--;
		}
	}
	for (std::vector< std::pair<int, int> >::iterator it = tmpv.begin(); it != tmpv.end(); it++)
	{
		std::cout << "The first = " << it->first << " ; The scond : " << it->second << std::endl;
		if (it->first > it->second)
		{
			tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
		std::cout << "The first = " << it->first << " ; The scond : " << it->second << std::endl;
	}

}


void	PmergeMe::SortDeque(void)
{
	std::deque<std::pair<int, int> >		tmpv;
	int										tmpi;
	int										tmp;

	for (std::deque<int>::iterator it = this->_deque.begin(); it != this->_deque.end(); it++)
	{
		tmpi = *it;
		it++;
		if (it != this->_deque.end())
		{
			tmpv.push_back(std::make_pair(tmpi, *it));
		}
		else {
			tmpv.push_back(std::make_pair(tmpi, -1));
			it--;
		}
	}
	for (std::deque< std::pair<int, int> >::iterator it = tmpv.begin(); it != tmpv.end(); it++)
	{
		std::cout << "The first = " << it->first << " ; The scond : " << it->second << std::endl;
		if (it->first > it->second)
		{
			tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
		std::cout << "The first = " << it->first << " ; The scond : " << it->second << std::endl;
	}

}

PmergeMe & PmergeMe::operator=(const PmergeMe & p)
{
	if (this != &p)
	{
	}
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
}
