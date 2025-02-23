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

		~Fixed();
};
std::ostream& operator<<(std::ostream& os, const Fixed &point);

#endif