#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class Fixed
{
	private :
		int	fixed_point;
		static const int bits = 8;
	public :
		Fixed();
		Fixed(const float val);
		Fixed(const int val);
		Fixed(const Fixed & val);
		~Fixed();
		Fixed &operator=(const Fixed &cp);
		int getRawBits(void) const;
		void setRawBits(const int val);
		float toFloat(void) const;
		int toInt(void) const;
		Fixed &operator++(int);
		Fixed &operator++(void);
		Fixed &operator--(int);
		Fixed &operator--(void);
		Fixed &operator+(float val);
		Fixed &operator-(float val);
};

std::ostream & operator<<(std::ostream & os, const Fixed &fixed);

#endif
