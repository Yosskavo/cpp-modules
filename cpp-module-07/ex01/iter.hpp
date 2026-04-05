#ifndef ITER_HPP
# define ITER_HPP

#include <cstdio>

template <typename T, typename Y>
	void iter(T *arr, const size_t & size, Y func)
	{
		for (size_t	i = 0; i < size; i++)
		{
			func(arr[i]);
		}
	}

#endif
