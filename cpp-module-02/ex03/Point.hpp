#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private :
		Fixed x;
		Fixed y;

	public :
		Point(void);
		Point(const float f_one, const float f_two);
		Point(const Point &point);
		~Point(void);
		Point &operator=(const Point &point);
		Fixed getX(void) const;
		Fixed getY(void) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
