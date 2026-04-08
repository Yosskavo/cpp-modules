#include "Span.hpp"
#include <sys/types.h>
#include <algorithm>
#include <numeric>
#include <vector>

Span::Span(unsigned int N)
{
	_arr_pos = 0;
	_array = new int[N]();
	_size = N;
}

void	Span::addNumber(int n)
{
	if (_arr_pos == _size)
	{
		throw OutOfLimit();
	}
	_array[_arr_pos] = n;
	_arr_pos++;
}

int	Span::longestSpan(void)
{
	if (_arr_pos < 2)
		throw NotEnoughElements();
	return (*(std::max_element(_array, _array + _arr_pos)) - *(std::min_element(_array, _arr_pos + _array)));
}

int Span::shortestSpan(void)
{
	if (_arr_pos < 2)
		throw NotEnoughElements();
	int *dublicated = new int[this->_arr_pos]();
	std::copy(this->_array, this->_array + this->_arr_pos, dublicated);
	std::sort(dublicated, dublicated + this->_arr_pos);
	std::vector<int> v(this->_arr_pos);
	std::adjacent_difference(dublicated, dublicated + this->_arr_pos, v.begin());
	std::vector<int>::iterator i;
	i = std::min_element(v.begin() + 1, v.end());
	delete [] dublicated;
	return (*i);
}

void Span::RangeOfIterators(int *start, unsigned int size)
{
	if (this->_arr_pos == this->_size || this->_arr_pos + size > this->_size)
	{
		throw SmallPlace();
	}
	for (unsigned int i = 0; i < size; i++)
	{
		this->_array[i + this->_arr_pos] = start[i];
	}
	this->_arr_pos += size;
}

Span::~Span(void)
{
	delete [] this->_array;
}

