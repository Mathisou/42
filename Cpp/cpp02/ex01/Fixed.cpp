#include "Fixed.hpp"

Fixed::Fixed(void) : _nb(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const nb) : _nb(nb << _bits){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const nb) : _nb((int)roundf(nb * (1 << _bits))){
	std::cout << "Float constructor called" << std::endl;
	// this->_nb = nb << this->_bits;
}

Fixed::Fixed(Fixed const & src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt( void ) const{
	return _nb >> _bits;
}

float Fixed::toFloat( void ) const{
	return _nb / (float)(1 << _bits);
}

int Fixed::getRawBits(void) const{
	return this->_nb;
}

void Fixed::setRawBits(int const raw){
	this->_nb = raw;
}

Fixed & Fixed::operator=( Fixed const & rhs){
	std::cout << "Assignation operator called" << std::endl;
	this->_nb = rhs.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs){

	o << rhs.toFloat();
	return o;
}
