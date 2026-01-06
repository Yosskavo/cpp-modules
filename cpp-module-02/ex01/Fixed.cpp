#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed & val)
{
	fixed_point = val.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

int Fixed::getRawBits(void)
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

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

