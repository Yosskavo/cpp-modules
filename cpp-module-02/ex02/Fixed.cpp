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
	std::cout << "Copy assignment operator calle" << std::endl;
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

Fixed & Fixed::operator++(int)
{

}

Fixed & Fixed::operator++(void)
{

}




