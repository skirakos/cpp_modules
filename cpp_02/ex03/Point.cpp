#include "Point.hpp"

Point::Point() : x(0), y(0) {} //because x and y are constants, so, they can be initilized only like this, because in this way they are called and set when the object is created

Point::Point(const float a, const float b) : x(a), y(b) {}

Point::Point(const Point& original) : x(original.x), y(original.y) {}

Point& Point::operator=(const Point& original) {
	(void)original;
	return (*this);
}

float	Point::getX() const {
	return (x.toFloat());
}
float Point::getY() const {
	return (y.toFloat());
}

Point::~Point() {}