#include <iostream>
#include "Point.hpp"

Point::Point(){
	x.setRawBits(0);
	y.setRawBits(0);
}

Point::~Point(){}

Point::Point(const float x, const float y){
	setPoints(x, y);
}

Point::Point(const Point &p){
	*this = p;
}

Point& Point::operator=(const Point &p){
	if (this == &p){
		return *this;
	}

	this->x = p.getX();
	this->y = p.getY();
	return *this;
}

void Point::setX(const float x){
	this->x.setRawBits(x);
}

void Point::setY(const float y){
	this->y.setRawBits(y);
}

void Point::setPoints(const float x, const float y){
	setX(x);
	setY(y);
}

Fixed Point::getX() const {
	return x;
}

Fixed Point::getY() const {
	return y;
}