#include "Point.hpp"

Fixed side(Point const & P_check, Point const & P_one, Point const & P_two)
{
	Fixed a;
	Fixed b;

	return ( (P_check.getX() - P_two.getX()) * (P_one.getY() - P_two.getY()) -
			(P_one.getX() - P_two.getX()) * (P_check.getY() - P_two.getY()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed d_one, d_two, d_tree;

	d_one  = side(point, a, b);
	d_two  = side(point, b, c);
	d_tree = side(point, c, a);

	bool all_pos = (d_one > 0) && (d_two > 0) && (d_tree > 0);
	bool all_neg = (d_one < 0) && (d_two < 0) && (d_tree < 0);
	return (all_pos || all_neg);
}
