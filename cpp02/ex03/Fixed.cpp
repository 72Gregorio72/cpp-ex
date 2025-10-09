# include <iostream>
# include <cmath>
# include "Fixed.hpp"

Fixed::Fixed(){
	//std::cout << "Default constructor called" << std::endl;
	fixedPointValue = 0;
};

Fixed::Fixed (const Fixed &other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other) {
		return *this;
	}

	setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
	//std::cout << "Int constructor called" << std::endl;
	fixedPointValue = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	//std::cout << "Float constructor called" << std::endl;
	fixedPointValue = roundf(floatValue * (1 << fractionalBits));
}

float Fixed::toFloat( void ) const {
	return (float)fixedPointValue / (1 << fractionalBits);
}

int Fixed::toInt( void ) const {
	return fixedPointValue >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &other) const {
	return this->fixedPointValue > other.fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->fixedPointValue < other.fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->fixedPointValue >= other.fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->fixedPointValue <= other.fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->fixedPointValue == other.fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->fixedPointValue != other.fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
	this->fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->fixedPointValue++;
	return temp;
}

Fixed &Fixed::operator--() {
	this->fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->fixedPointValue--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return a;
	return b;
}

int Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	fixedPointValue = raw;
};