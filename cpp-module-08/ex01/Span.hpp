#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>

class Span
{
	private :
		int			*_array;
		unsigned int			_arr_pos;
		unsigned int _size;
	public :
		Span(unsigned int N);
		void addNumber(int n);
		int	longestSpan(void);
		int	shortestSpan(void);
		void RangeOfIterators(int *start, unsigned int size);
		~Span(void);

		class OutOfLimit : public std::exception
		{
			public :
				const char * what() const throw()
				{
					return ("The array is full");
				}
		};
		class NotEnoughElements : public std::exception 
		{
			public :
				const char * what() const throw()
				{
					return ("The Elements are not enough to do this operator's");
				}
		};
		class SmallPlace : public std::exception
		{
			public :
				const char * what() const throw() 
				{
					return ("The size to add is more than place left");
				};
		};
};

#endif
