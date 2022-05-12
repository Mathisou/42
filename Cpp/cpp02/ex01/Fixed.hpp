#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed{

	private:

	int _nb;
	static const int _bits = 8;

	public:
	
	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(const int nb);
	Fixed(const float nb);
	~Fixed(void);
	Fixed & operator=( Fixed const & rhs);
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif