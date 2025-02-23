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
	this->rawValue = original.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout<<"getRawBits member function called\n";
	return rawValue;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->rawValue = raw;
}

Fixed::~Fixed() {
	std::cout<<"Destructor called\n";
}
