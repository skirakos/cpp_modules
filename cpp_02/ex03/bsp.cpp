#include "Point.hpp"

float	ft_abs(float num) {
	if (num < 0)
		return (-num);
	return (num);
}
float triangleArea(Point a, Point b, Point c) {
	return ft_abs(a.getX() * (b.getY() - c.getY()) +
                    b.getX() * (c.getY() - a.getY()) +
                    c.getX() * (a.getY() - b.getY()));
}


bool bsp( Point const a, Point const b, Point const c, Point const point) {
	float	areaABC = triangleArea(a, b, c);
	float	areaPBC = triangleArea(point, b, c);
	float	areaAPC = triangleArea(a, point, c);
	float	areaABP = triangleArea(a, b, point);
	if ((point.getX() == a.getX() && point.getY() == a.getY())
		|| (point.getX() == b.getX() && point.getY() == b.getY())
		|| (point.getX() == c.getX() && point.getY() == c.getY()))
		return (false);
	if ((areaABC == areaPBC + areaAPC + areaABP) && areaPBC != 0 && areaAPC != 0 && areaABP != 0)
		return (true);
	return (false);
}