#include "Point.hpp"
#include <iostream>

Point::Point(void) : x(0), y(0)
{
}

Point::Point(const float f_one, const float f_two) : x(f_one) , y(f_two)
{
}

Point::Point(const Point &point) : x(point.x) , y(point.y)
{
}

Point & Point::operator=(const Point &point)
{
	(void)point;
	return (*this);
}

Point::~Point(void)
{
	std::cout << "Point destructor called" << std::endl;
}

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}
