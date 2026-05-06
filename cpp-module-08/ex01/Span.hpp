#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>

class Span
{
	private :
		std::vector<int>			_array;
		unsigned int _size;
	public :
		Span(unsigned int N);
		void addNumber(int n);
		int	longestSpan(void);
		int	shortestSpan(void);
		~Span(void);

		template <typename T>
			void	RangeOfIterators(typename T::iterator start, typename T::iterator end, unsigned int size)
			{
				if (_array.size() == this->_size || _array.size() + size > this->_size)
				{
					throw SmallPlace();
				}
				for (typename T::iterator it = start; it != end && size; it++)
				{
					_array.push_back(*it);
					size--;
				}
			}

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
