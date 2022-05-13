#include "Fixed.hpp"

int main( void ) {
	
	Fixed a;
	Fixed b( Fixed( 5.05f ) + Fixed( 2 ) );
	Fixed c( Fixed( 5.05f ) - Fixed( 2 ) );
	Fixed const d( Fixed( 5.05f ) / Fixed( 2 ) );
	Fixed const e( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl << std::endl;

	std::cout << "pre incrementation : " << ++a << std::endl;
	std::cout << "                     " << a << std::endl;
	std::cout << "post incrementation: " << a++ << std::endl;
	std::cout << "                     " << a << std::endl;
	std::cout << "pre decrementation : " << --a << std::endl;
	std::cout << "                     " << a << std::endl;
	std::cout << "post decrementation: " << a-- << std::endl;
	std::cout << "                     " << a << std::endl << std::endl;
	
	std::cout << "addition      :      " << b << std::endl;
	std::cout << "soustraction  :      " << c << std::endl;
	std::cout << "division      :      " << d << std::endl;
	std::cout << "multiplication:      " << e << std::endl << std::endl;

	std::cout << "Which is the higher between d and e (const): " << Fixed::max( e, d ) << std::endl;
	std::cout << "Which is the lower between c and b         : " << Fixed::min( c, b ) << std::endl << std::endl;

	if (a < b)
		std::cout << "comparaison succeed" << std::endl;
	if (b > a)
		std::cout << "comparaison succeed" << std::endl;
	if (b >= a)
		std::cout << "comparaison succeed" << std::endl;
	if (a <= b)
		std::cout << "comparaison succeed" << std::endl;
	if (b == b)
		std::cout << "comparaison succeed" << std::endl;
	if (b != a)
		std::cout << "comparaison succeed" << std::endl;

	return 0;
}