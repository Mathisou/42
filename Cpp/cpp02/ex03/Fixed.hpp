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
	bool operator<( Fixed const & rhs) const;
	bool operator>( Fixed const & rhs) const;
	bool operator>=( Fixed const & rhs) const;
	bool operator<=( Fixed const & rhs) const;
	bool operator==( Fixed const & rhs) const;
	bool operator!=( Fixed const & rhs) const;
	Fixed operator+( Fixed const & rhs) const;
	Fixed operator-( Fixed const & rhs) const;
	Fixed operator*( Fixed const & rhs) const;
	Fixed operator/( Fixed const & rhs) const;
	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed & min(Fixed & nb1, Fixed & nb2);
	static Fixed const & min(Fixed const & nb1, Fixed const & nb2);
	static Fixed & max(Fixed & nb1, Fixed & nb2);
	static Fixed const & max(Fixed const & nb1, Fixed const & nb2);
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif