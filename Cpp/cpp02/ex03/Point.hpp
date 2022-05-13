#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point{

	private:

	Fixed const _x;
	Fixed const _y;

	public:

	Point(void);
	Point(const float x, const float y);
	Point(const Point & rhs);
	~Point(void);
	Point & operator=( Point const & rhs);
	const Fixed get_x() const;
	const Fixed get_y() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif