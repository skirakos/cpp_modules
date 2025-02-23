#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					rawValue;
		static const int	bits = 8;

	public:

		Fixed();
		Fixed(const Fixed& original);
		Fixed(const int n);
		Fixed(const float n);
		Fixed& operator=(const Fixed& original);
	
		int getRawBits( void ) const;

		void setRawBits( int const raw );

		float toFloat( void ) const;

		int toInt( void ) const;

		// Comparison operators
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		// Arithmetic operators
		const Fixed operator+(const Fixed& other) const;
		const Fixed operator-(const Fixed& other) const;
		const Fixed operator*(const Fixed& other) const;
		const Fixed operator/(const Fixed& other) const;

		// Overloaded member functions
		static Fixed& min(Fixed& a, Fixed& b); //why static? because this function works with 2 objects we don't need this object here (by default member functions take this obj also,from the left, or wee need to call them like this obj.funct, but here we use these functions for other 2 objects without this object)
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		// increment/decrement operations
		Fixed& operator++();
		Fixed& operator--();
		const Fixed operator++(int);
		const Fixed operator--(int);

		~Fixed();
};
std::ostream& operator<<(std::ostream& os, const Fixed &point); //dzaxiny Fixed chi,that's why grum enq drsum, qani vor ete class i mej greinq dzaxiny nuynpes vercnelu er Fixed (this) object y, bayc mer depqum da ostream objecta

#endif

// Why static?
// This function compares two objects and returns the smaller one.

// It does not belong to any specific object, so we don’t need this.

// Non-static functions require an object (obj.function()), but here, we just need two given objects.