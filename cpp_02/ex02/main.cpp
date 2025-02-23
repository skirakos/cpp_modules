#include "Fixed.hpp"

int main( void ) {
// Fixed f1(5.05f);
// Fixed f2(2);
// std::cout << "5.05 rawValue: " << f1.getRawBits() << std::endl;
// std::cout << "2 rawValue: " << f2.getRawBits() << std::endl;


	Fixed a;
	Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout<< "a: " << a << std::endl;
	std::cout << "a++: "<< a++ << std::endl;
	std::cout<< "a: " << a << std::endl;
	std::cout<< "b: " << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}