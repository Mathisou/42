#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point){
	float prod_vec;
	float prod_vec2;
	float prod_vec3;

	prod_vec = (((a.get_x()).toFloat() - (point.get_x()).toFloat()) * ((b.get_y()).toFloat() - (point.get_y()).toFloat())) - (((a.get_y()).toFloat() - (point.get_y()).toFloat()) * ((b.get_x()).toFloat() - (point.get_x()).toFloat()));
	prod_vec2 = (((b.get_x()).toFloat() - (point.get_x()).toFloat()) * ((c.get_y()).toFloat() - (point.get_y()).toFloat())) - (((b.get_y()).toFloat() - (point.get_y()).toFloat()) * ((c.get_x()).toFloat() - (point.get_x()).toFloat()));
	prod_vec3 = (((c.get_x()).toFloat() - (point.get_x()).toFloat()) * ((a.get_y()).toFloat() - (point.get_y()).toFloat())) - (((c.get_y()).toFloat() - (point.get_y()).toFloat()) * ((a.get_x()).toFloat() - (point.get_x()).toFloat()));
	if ((prod_vec < 0 && prod_vec2 < 0 && prod_vec3 < 0) || (prod_vec > 0 && prod_vec2 > 0 && prod_vec3 > 0))
		return (true);
	return false;
}