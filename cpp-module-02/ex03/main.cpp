#include "Point.hpp"
#include <iostream>

int main( void ) {
    Point const a(0, 0);
    Point const b(10, 0);
    Point const c(0, 10);
	Point const p(2,2);

	if (bsp(a, b, c, p))
		std::cout << "yes its inside" << std::endl;
    return (0);
}
