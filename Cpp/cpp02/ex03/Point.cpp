#include "Point.hpp"

Point::Point(void) : _x(0), _y(0){
	;
}

Point::Point(const float x, const float y) : _x(x), _y(y){
	;
}

Point::Point(const Point & rhs) : _x(rhs._x), _y(rhs._y){
	;
}

Point::~Point(void){
	;
}

Point & Point::operator=( Point const & rhs){
	if (this == &rhs)
		return *this;
	return *this;
}

const Fixed Point::get_x() const{
	return (this->_x);
}

const Fixed Point::get_y() const{
	return (this->_y);
}
