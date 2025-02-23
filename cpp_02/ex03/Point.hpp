#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float a, const float b);
		Point(const Point& original);
		Point& operator=(const Point& original);

		float getX() const;
		float getY() const;
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
