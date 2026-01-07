#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private :
		int	fixed_point;
		static const int bits = 8;
	public :
		Fixed();
		Fixed(const Fixed &val);
		Fixed &operator=(const Fixed &cp);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(const int val);
};

#endif
