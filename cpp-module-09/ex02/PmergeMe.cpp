#include "PmergeMe.hpp"
#include <bits/types/struct_timeval.h>
#include <cstdlib>
#include <climits>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <sys/time.h>

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
	char		*c;

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

void	PmergeMe::print_it(const std::string	&str)
{
	if (str == "vector")
		for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++)
		{
			std::cout << *it  << " ";
		}
	else
		for (std::deque<int>::iterator it = this->_deque.begin(); it != this->_deque.end(); it++)
		{
			std::cout << *it  << " ";
		}
}

template <typename	T>
	T	jacobsthal_generator(int size)
	{
		T	jacobsthal;
		
		jacobsthal.push_back(1);
		jacobsthal.push_back(3);

		while (jacobsthal.back() < size)
		{
			jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
		}
		return (jacobsthal);
	}

template <typename T>
	void ft_swap(T & contai)
	{
		T tmp = contai;

		contai[1] = contai[0];
		contai[0] = tmp[1];
	}

template <typename T>
	void	ft_sort_winers(T & tmpt)
	{
		size_t		mid;
		if (tmpt.size() <= 1)
			return ;
		mid = tmpt.size() / 2;
		T l(tmpt.begin() + mid, tmpt.end());
		T r(tmpt.begin(), tmpt.begin() + mid);
		ft_sort_winers<T>(r);
		ft_sort_winers<T>(l);

		size_t i = 0, j = 0, k = 0;
		while (i < r.size() && j < l.size())
		{
			if (r[i].first > l[j].first)
			{
				tmpt[k] = l[j];
				j++;
			}
			else{
				tmpt[k] = r[i];
				i++;
			}
			k++;
		}
		while (j < l.size())
		{
			tmpt[k] = l[j];
			j++;
			k++;
		}
		while (i < r.size())
		{
			tmpt[k] = r[i];
			i++;
			k++;
		}
	}

void	PmergeMe::SortVector(void)
{
	std::vector<std::pair<int, int> >		tmpv;
	std::vector<int>						jacobsthal;
	int										tmpi = -1;
	int										tmp;
	struct timeval							end, start;

	if (this->_vector.size() <= 1)
		throw std::runtime_error("not enough numbers");
	gettimeofday(&start, NULL);
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++)
	{
		tmpi = *it;
		it++;
		if (it != this->_vector.end())
		{
			tmpv.push_back(std::make_pair(tmpi, *it));
			tmpi = -1;
		}
		else {
			it--;
		}
	}
	for (std::vector< std::pair<int, int> >::iterator it = tmpv.begin(); it != tmpv.end(); it++)
	{
		if (it->first < it->second)
		{
			tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	this->_vector.clear();
	ft_sort_winers(tmpv);
	for (std::vector< std::pair<int, int> >::iterator it = tmpv.begin(); it != tmpv.end(); it++)
	{
		this->_vector.push_back(it->first);
	}
	this->_vector.insert(this->_vector.begin(), tmpv[0].second);
	jacobsthal = jacobsthal_generator<std::vector<int> >(tmpv.size());
	int last_jac = 1;
	int	current_jac;
	for (size_t i = 0; i < jacobsthal.size() ; i++)
	{
		current_jac = jacobsthal[i];
		for (int j = current_jac; j > last_jac; j--)
		{
			if (static_cast<size_t>(j) > tmpv.size())
				continue ;
			int val = tmpv[j - 1].second;
			this->_vector.insert(std::lower_bound(this->_vector.begin(), this->_vector.end(), val), val);
		}
		last_jac = current_jac;
	}
	gettimeofday(&end, NULL);
	if (tmpi != -1)
		this->_vector.insert(std::lower_bound(this->_vector.begin(), this->_vector.end(), tmpi), tmpi);
	this->_time_vector = ((end.tv_sec - start.tv_sec) * 1000000.0) + (end.tv_usec - start.tv_usec);
}

void	PmergeMe::SortDeque(void)
{
	std::deque<std::pair<int, int> >		tmpd;
	std::deque<int>						jacobsthal;
	int										tmpi;
	int										tmp;
	struct timeval							end, start;

	if (this->_deque.size() <= 1)
		throw std::runtime_error("not enough numbers");
	gettimeofday(&start, NULL);
	for (std::deque<int>::iterator it = this->_deque.begin(); it != this->_deque.end(); it++)
	{
		tmpi = *it;
		it++;
		if (it != this->_deque.end())
		{
			tmpd.push_back(std::make_pair(tmpi, *it));
			tmpi = -1;
		}
		else {
			it--;
		}
	}
	for (std::deque< std::pair<int, int> >::iterator it = tmpd.begin(); it != tmpd.end(); it++)
	{
		if (it->first < it->second)
		{
			tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	this->_deque.clear();
	ft_sort_winers(tmpd);
	for (std::deque< std::pair<int, int> >::iterator it = tmpd.begin(); it != tmpd.end(); it++)
	{
		this->_deque.push_back(it->first);
	}
	this->_deque.insert(this->_deque.begin(), tmpd[0].second);
	jacobsthal = jacobsthal_generator<std::deque<int> >(tmpd.size());
	int last_jac = 1;
	int	current_jac;
	for (size_t i = 0; i < jacobsthal.size() ; i++)
	{
		current_jac = jacobsthal[i];
		for (int j = current_jac; j > last_jac; j--)
		{
			if (static_cast<size_t>(j) > tmpd.size())
				continue ;
			int val = tmpd[j - 1].second;
			this->_deque.insert(std::lower_bound(this->_deque.begin(), this->_deque.end(), val), val);
		}
		last_jac = current_jac;
	}
	if (tmpi != -1)
		this->_deque.insert(std::lower_bound(this->_deque.begin(), this->_deque.end(), tmpi), tmpi);
	gettimeofday(&end, NULL);
	this->_time_deque = ((end.tv_sec - start.tv_sec) * 1000000.0) + (end.tv_usec - start.tv_usec);
} 

void	PmergeMe::print_time(const std::string & str) const 
{
	if (str == "vector")
	{
		std::cout << "time to process a range of " << this->_vector.size() << " element with std::vector " << this->_time_vector << " us" << std::endl;
	}
	else
	{
		std::cout << "time to process a range of " << this->_deque.size() << " element with std::deque " << this->_time_deque << " us" << std::endl;
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



