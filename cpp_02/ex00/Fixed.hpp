#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					rawValue;
		static const int	bits = 8;

	public:

		Fixed();
		Fixed(const Fixed& original);
		Fixed& operator=(const Fixed& original);

		int getRawBits( void ) const;

		void setRawBits( int const raw );

		~Fixed();
};

#endif