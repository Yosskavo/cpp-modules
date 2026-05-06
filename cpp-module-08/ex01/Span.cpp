#include "Span.hpp"
#include <sys/types.h>
#include <algorithm>
#include <numeric>
#include <vector>

Span::Span(unsigned int N)
{
	_size = N;
}

void	Span::addNumber(int n)
{
	if (this->_array.size() >= _size)
	{
		throw OutOfLimit();
	}
	this->_array.push_back(n);
}

int	Span::longestSpan(void)
{
	if (this->_array.size() < 2)
		throw NotEnoughElements();
	return (*(std::max_element(_array.begin(), _array.end())) - *(std::min_element(_array.begin(), _array.end())));
}

int Span::shortestSpan(void)
{
	if (_array.size() < 2)
		throw NotEnoughElements();
	std::vector<int> v = _array;
	std::sort(v.begin(), v.end());
	std::adjacent_difference(v.begin(), v.end(), v.begin());
	std::vector<int>::iterator i;
	i = std::min_element(v.begin() + 1, v.end());
	return (*i);
}


Span::~Span(void)
{
	_array.clear();
}

