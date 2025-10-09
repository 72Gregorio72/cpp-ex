#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{

	Fixed area_abc = Fixed(0.5f) * ( a.getX() * (b.getY() - c.getY()) +
		b.getX() * (c.getY() - a.getY()) +
		c.getX() * (a.getY() - b.getY()));
	
	Fixed area_abp = Fixed(0.5f) * ( a.getX() * (b.getY() - point.getY()) +
		b.getX() * (point.getY() - a.getY()) +
		point.getX() * (a.getY() - b.getY()));
	
	Fixed area_acp = Fixed(0.5f) * ( a.getX() * (point.getY() - c.getY()) +
		point.getX() * (c.getY() - a.getY()) +
		c.getX() * (a.getY() - point.getY()));
	
	Fixed area_bcp = Fixed(0.5f) * ( point.getX() * (b.getY() - c.getY()) +
		b.getX() * (c.getY() - point.getY()) +
		c.getX() * (point.getY() - b.getY()));
	
	if (std::abs(area_abc.toFloat()) !=
		std::abs(area_abp.toFloat()) +
		std::abs(area_acp.toFloat()) +
		std::abs(area_bcp.toFloat()))
		return false;

	return true;
}