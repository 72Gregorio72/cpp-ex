#include <iostream>
#include <string>
#include <cstdlib>
#include "Point.hpp"

bool validateTriangle(Point const a, Point const b, Point const c) {
	if ((a.getX() == b.getX() && a.getY() == b.getY()) ||
		(a.getX() == c.getX() && a.getY() == c.getY()) ||
		(b.getX() == c.getX() && b.getY() == c.getY())) {
		std::cout << "Almeno due punti sono identici." << std::endl;
		return false;
	}

	if ((a.getX() == b.getX() && b.getX() == c.getX()) ||
		(a.getY() == b.getY() && b.getY() == c.getY())) {
		std::cout << "I punti sono collineari." << std::endl;
		return false;
	}

	return true;
}

int main(void) {
	int x, y;
	std::string input;

	std::cout << "---- Insert Point A ----" << std::endl;
	std::cout << "X: ";
	std::getline(std::cin, input);
	x = std::atoi(input.c_str());
	std::cout << "Y: ";
	std::getline(std::cin, input);
	y = std::atoi(input.c_str());
	Point a(x, y);

	std::cout << "---- Insert Point B ----" << std::endl;
	std::cout << "X: ";
	std::getline(std::cin, input);
	x = std::atoi(input.c_str());
	std::cout << "Y: ";
	std::getline(std::cin, input);
	y = std::atoi(input.c_str());
	Point b(x, y);

	std::cout << "---- Insert Point C ----" << std::endl;
	std::cout << "X: ";
	std::getline(std::cin, input);
	x = std::atoi(input.c_str());
	std::cout << "Y: ";
	std::getline(std::cin, input);
	y = std::atoi(input.c_str());
	Point c(x, y);

	std::cout << "---- Insert Point B ----" << std::endl;
	std::cout << "X: ";
	std::getline(std::cin, input);
	x = std::atoi(input.c_str());
	std::cout << "Y: ";
	std::getline(std::cin, input);
	y = std::atoi(input.c_str());
	Point point(x, y);

	if (!validateTriangle(a, b, c))
		return 1;
	if (bsp(a, b, c, point))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is outside the triangle" << std::endl;
	return 0;
}
