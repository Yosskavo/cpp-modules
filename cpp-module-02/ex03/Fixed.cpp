#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &val) : fixed_point(val.fixed_point)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point = val << bits;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
 	fixed_point = roundf(val * (1 << bits));
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point);
}

void Fixed::setRawBits(int val)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixed_point = val;
}

Fixed & Fixed::operator=(const Fixed &cp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &cp)
		this->fixed_point = cp.fixed_point;
	return (*this);
}

std::ostream & operator<<(std::ostream & os, const Fixed & fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)fixed_point / (1 << bits));
}

int Fixed::toInt(void) const
{
	return (fixed_point >> bits);
}

bool Fixed::operator!=(const Fixed & obj) const
{
	if (this->fixed_point != obj.getRawBits()) 
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed & obj) const
{
	if (this->fixed_point == obj.getRawBits()) 
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed & obj) const
{
	if (this->fixed_point >= obj.getRawBits()) 
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed & obj) const
{
	if (this->fixed_point <= obj.getRawBits()) 
		return (true);
	return (false);
}

bool Fixed::operator>(const Fixed & obj) const
{
	if (this->fixed_point > obj.getRawBits()) 
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed & obj) const
{
	if (this->fixed_point < obj.getRawBits()) 
		return (true);
	return (false);
}

const Fixed &Fixed::min(const Fixed &fixedone, const Fixed &fixedtwo)
{
	if (fixedone.getRawBits() > fixedtwo.getRawBits())
		return (fixedtwo);
	return (fixedone);
}

const Fixed &Fixed::max(const Fixed &fixedone, const Fixed &fixedtwo)
{
	if (fixedone.getRawBits() > fixedtwo.getRawBits())
		return (fixedone);
	return (fixedtwo);
}

Fixed &Fixed::min(Fixed &fixedone, Fixed &fixedtwo)
{
	if (fixedone.getRawBits() > fixedtwo.getRawBits())
		return (fixedtwo);
	return (fixedone);
}

Fixed &Fixed::max(Fixed &fixedone, Fixed &fixedtwo)
{
	if (fixedone.getRawBits() > fixedtwo.getRawBits())
		return (fixedone);
	return (fixedtwo);
}

Fixed &Fixed::operator++(void)
{
	(this->fixed_point)++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	(this->fixed_point)--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	(this->fixed_point)++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	(this->fixed_point)--;
	return (tmp);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed tmp;

	tmp.fixed_point = this->fixed_point + fixed.fixed_point; 
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed tmp;

	tmp.fixed_point = this->fixed_point - fixed.fixed_point; 
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed tmp;
	long result;

	result = (long)this->fixed_point * (long)fixed.fixed_point;
	tmp.fixed_point = result >> this->bits; 
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed tmp;
	long result;

	if (fixed.fixed_point == 0)
		return (fixed);
	result = this->fixed_point << this->bits;
	tmp.fixed_point = result / fixed.fixed_point;
	return (tmp);
}
