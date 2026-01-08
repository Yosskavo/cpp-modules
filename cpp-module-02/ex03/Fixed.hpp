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
		Fixed operator++(int);
		Fixed &operator++(void);
		Fixed operator--(int);
		Fixed &operator--(void);
		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>(const Fixed &fixed) const;
		static const Fixed & min(const Fixed & fixedone, const Fixed &fixedtwo);
		static const Fixed & max(const Fixed & fixedone, const Fixed &fixedtwo);
		static Fixed & min(Fixed & fixedone, Fixed &fixedtwo);
		static Fixed & max(Fixed & fixedone, Fixed &fixedtwo);
};

std::ostream & operator<<(std::ostream & os, const Fixed &fixed);

#endif
