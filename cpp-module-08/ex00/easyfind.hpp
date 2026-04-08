#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

class NotFoundN : public std::exception
{
	public :
		const char * what() const throw()
		{
			return ("The element not found!");
		}
};

template <typename T>
	typename T::iterator easyfind(T &target, int n)
	{
		typename T::iterator i = std::find(target.begin(), target.end(), n);
		if (i == target.end())
			throw NotFoundN();
		return (i);
	}

#endif
