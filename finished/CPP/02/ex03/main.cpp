#include "Point.hpp"

void	check(Point const a, Point const b, Point const c, Point const p) {

	if (bsp(a, b, c, p) == true)
		std::cout << "Point ( " << p.getX() << ", " << p.getY() << " ) is INSIDE triangle ABC" << std::endl;
	else
		std::cout << "Point ( " << p.getX() << ", " << p.getY() << " ) is OUTSIDE triangle ABC" << std::endl;

}

int	main(void) {

	Point a;
	Point b(4.2, 0);
	Point c(2.987, -3.8);	

	std::cout << "Triangle ABC created with these coordinates :" << std::endl;
	std::cout << "A : ( " << a.getX() << ", " << a.getY() << " )" << std::endl;
	std::cout << "B : ( " << b.getX() << ", " << b.getY() << " )" << std::endl;
	std::cout << "C : ( " << c.getX() << ", " << c.getY() << " )" << std::endl << std::endl;

	Point p1(2.1, -1.82);
	Point p2(0.1, -0.1);
	Point p3(3, -1);

	Point p4 = b;
	Point p5(2.23456, 0);
	Point p6(5.12, -50);

	check(a, b, c, p1);
	check(a, b, c, p2);
	check(a, b, c, p3);
	check(a, b, c, p4);
	check(a, b, c, p5);
	check(a, b, c, p6);

	return 0;
}