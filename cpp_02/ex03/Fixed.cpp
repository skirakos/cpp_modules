#include "Fixed.hpp"

// Constructors 

Fixed::Fixed() {
	rawValue = 0;
	//std::cout<<"Default constructor called\n";
}

Fixed::Fixed (const int n) {
	//std::cout<<"Int constructor called\n";
	this->rawValue = n * 256;
}

Fixed::Fixed(float value) {
    this->rawValue = roundf(value * (1 << bits));
}


Fixed::Fixed(const Fixed& original) {
	//std::cout<<"Copy constructor called\n";
	// this->rawValue = original.rawValue;
	*this = original; //why so???
}

Fixed& Fixed::operator=(const Fixed& original) {
	//std::cout<<"Copy assignment operator called\n";
	this->rawValue = original.rawValue;
	return *this;
}
// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
	return (this->rawValue > other.rawValue);
}
bool Fixed::operator<(const Fixed& other) const {
	return (this->rawValue < other.rawValue);
}
bool Fixed::operator>=(const Fixed& other) const {
	return (this->rawValue >= other.rawValue);
}
bool Fixed::operator<=(const Fixed& other) const {
	return (this->rawValue <= other.rawValue);
}
bool Fixed::operator==(const Fixed& other) const {
	return (this->rawValue == other.rawValue);
}
bool Fixed::operator!=(const Fixed& other) const {
	return (this->rawValue != other.rawValue);
}

// Arithmetic operators
const Fixed Fixed::operator+(const Fixed& other) const {
	return (Fixed(this->rawValue + other.rawValue));
}
const Fixed Fixed::operator-(const Fixed& other) const {
	return (Fixed(this->rawValue - other.rawValue));
}

const Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;

	result.setRawBits((this->rawValue * other.rawValue) >> bits);
	return (result);
}

const Fixed Fixed::operator/(const Fixed& other) const {
	Fixed	result;

	result.setRawBits((this->getRawBits() << this->bits) / other.getRawBits());
	return (result);
}

//Overloaded member functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return ((a < b) ? a : b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return ((a > b) ? a : b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return ((a < b) ? a : b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return ((a > b) ? a : b);
}

// increment/decrement
Fixed &Fixed::operator++() {
	this->rawValue++;
	return (*this);
}

Fixed &Fixed::operator--() {
	this->rawValue--;
	return (*this);
}

const Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	++(*this);
	return (tmp);
}

const Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	--(*this);
	return (tmp);
}



int Fixed::getRawBits( void ) const {
	//std::cout<<"getRawBits member function called\n";
	return rawValue;
}

void Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->rawValue = raw;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(rawValue) / 256.0f;
}


int Fixed::toInt( void ) const {
	return (rawValue) / 256;
}
Fixed::~Fixed() {
	//std::cout<<"Destructor called\n";
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
