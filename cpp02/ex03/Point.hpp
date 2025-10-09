#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point{
	private:
		Fixed x, y;
	
	public:
		Point();
		~Point();
		Point(const float x, const float y);
		Point (const Point &p);
		Point &operator=(const Point &p);
		
		Fixed getX() const;
		Fixed getY() const;

		void setX(const float x);
		void setY(const float y);
		void setPoints(const float x, const float y);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif