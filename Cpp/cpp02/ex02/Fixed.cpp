#include "Fixed.hpp"

Fixed::Fixed(void) : _nb(0){
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const nb) : _nb(nb << _bits){
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const nb) : _nb((int)roundf(nb * (1 << _bits))){
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src){
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void){
	// std::cout << "Destructor called" << std::endl;
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
	// std::cout << "Assignation operator called" << std::endl;
	this->_nb = rhs.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs){

	o << rhs.toFloat();
	return o;
}



Fixed Fixed::operator+( Fixed const & rhs) const{
	// std::cout << "Addition operator called with " << _nb << " and " << rhs.toInt() << std::endl;

	return Fixed(toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-( Fixed const & rhs) const{
	// std::cout << "Substraction operator called with " << _nb << " and " << rhs.toInt() << std::endl;

	return Fixed(toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*( Fixed const & rhs) const{
	// std::cout << "Multiplication operator called with " << _nb << " and " << rhs.toInt() << std::endl;

	return Fixed(toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/( Fixed const & rhs) const{
	// std::cout << "Division operator called with " << _nb << " and " << rhs.toInt() << std::endl;

	return Fixed(toFloat() / rhs.toFloat());
}

Fixed Fixed::operator++(){
	// std::cout << "Pre-incrementation operator called" << std::endl;

	Fixed tmp;
	tmp._nb = ++_nb;
	return tmp;
}

Fixed Fixed::operator++(int){
	// std::cout << "Post-incrementation operator called" << std::endl;

	Fixed tmp;
	tmp._nb = _nb++;
	return tmp;
}

Fixed Fixed::operator--(){
	// std::cout << "Pre-decrementation operator called" << std::endl;

	Fixed tmp;
	tmp._nb = --_nb;
	return tmp;
}

Fixed Fixed::operator--(int){
	// std::cout << "Post-decrementation operator called"<< std::endl;

	Fixed tmp;
	tmp._nb = _nb--;
	return tmp;
}

bool Fixed::operator>(Fixed const & rhs) const{
	std::cout << "Superior operator called" << std::endl;
	return (_nb > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const & rhs) const{
	std::cout << "Inferior operator called" << std::endl;
	return (_nb < rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const & rhs) const{
	std::cout << "inferior or equal operator called" << std::endl;
	return (_nb <= rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const & rhs) const{
	std::cout << "Superior or equal operator called" << std::endl;
	return (_nb >= rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const & rhs) const{
	std::cout << "different operator called" << std::endl;
	return (_nb != rhs.getRawBits());
}

bool Fixed::operator==(Fixed const & rhs) const{
	std::cout << "equivalent operator called" << std::endl;
	return (_nb == rhs.getRawBits());
}

Fixed & Fixed::min(Fixed & a, Fixed & b){
	return (a < b ? a : b);
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b){
	return (a < b ? a : b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b){
	return (a > b ? a : b);
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b){
	return (a > b ? a : b);
}

