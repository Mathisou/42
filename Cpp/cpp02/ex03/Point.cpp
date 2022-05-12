#include "Point.hpp"

#ifndef POINT_CPP
# define POINT_CPP

Point::Point(void) : _x(0), _y(0){
	;
}

Point::Point(const float x, const float y) : _x(x), _y(y){
	;
}

Point::Point(const Point & rhs){
	*this = rhs;
}

Point::~Point(void){
	;
}

Point & Point::operator=( Point const & rhs){
	this->_x = rhs.get_x();
	this->_y = rhs.get_y();
	return *this;
}

const Fixed Point::get_x() const{
	return (this->_x);
}

const Fixed Point::get_y() const{
	return (this->_y);
}

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
