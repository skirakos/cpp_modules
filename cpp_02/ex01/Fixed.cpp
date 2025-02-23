#include "Fixed.hpp"


Fixed::Fixed() {
	rawValue = 0;
	std::cout<<"Default constructor called\n";
}

Fixed::Fixed(const Fixed& original) {
	std::cout<<"Copy constructor called\n";
	// this->rawValue = original.rawValue;
	*this = original; //why so???
}

Fixed& Fixed::operator=(const Fixed& original) {
	std::cout<<"Copy assignment operator called\n";
	this->rawValue = original.rawValue;
	return *this;
}

// Fixed& Fixed::operator<<(const Fixed& n) {
// 	std::cout<<n.rawValue;
// }

Fixed::Fixed (const int n) {
	std::cout<<"Int constructor called\n";
	this->rawValue = n * 256;
}

Fixed::Fixed (const float n) {
	std::cout<<"Float constructor called\n";
	this->rawValue = roundf(n * 256.0f);
}

int Fixed::getRawBits( void ) const {
	std::cout<<"getRawBits member function called\n";
	return rawValue;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->rawValue = raw;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(rawValue) / 256.0f;
}
int Fixed::toInt( void ) const {
	return (rawValue) / 256;
}
Fixed::~Fixed() {
	std::cout<<"Destructor called\n";
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
} //????????
