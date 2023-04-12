#include "Point.hpp"

Fixed	get_vect_AB(Point const a, Point const b, Point const c, Point const p) {

	Fixed res;

	res = (a.getX() * (c.getY() - a.getY()) + (p.getY() - a.getY()) * (c.getX() - a.getX()) - p.getX() * (c.getY() - a.getY()))
		/ ((b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY()));

	return (res);
}

Fixed	get_vect_AC(Point const a, Point const b, Point const c, Point const p, Fixed vectAB) {

	Fixed res;

	res = (p.getY() - a.getY() - vectAB * (b.getY() - a.getY()))
		/ (c.getY() - a.getY());

	return (res);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	Fixed vectAB = get_vect_AB(a, b, c, point);
	Fixed vectAC = get_vect_AC(a, b, c, point, vectAB);

	if (vectAB > 0 && vectAC > 0 && vectAB + vectAC < 1)
		return (true);
	else
		return (false);
}
