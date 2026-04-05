#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <cstdio>

template <typename T>
	class Array
	{
		private :
			T* _array;
			unsigned int _size;
		public :
			Array(void)
			{
				_array = new T[0]();
				_size = 0;
			}
			Array(unsigned int n)
			{
				_array = new T[n]();
				_size = n;
			}
			Array(const Array & a)
			{
				this->_array = new T[0]();
				operator=(a);
			}
			Array & operator=(const Array & a)
			{
				if (this != &a)
				{
					this->_size = a.size();
					delete [] this->_array;
					this->_array = new T[this->_size]();
					for (unsigned int i = 0; i < this->_size; i++)
					{
						this->_array[i] = a._array[i];
					}
				}
				return (*this);
			}
			~Array(void)
			{
				delete [] this->_array;
			}
			unsigned int	size() const
			{
				return (_size);
			}
			T &operator[](unsigned int i)
			{
				if (this->_size <= i)
				{
					throw OutOfRange();
				}
				return (this->_array[i]);
			}
			class OutOfRange : public std::exception
			{
				const char *what() const throw()
				{
					return ("The index is out of range of the array");
				}
			};

	};

#endif
