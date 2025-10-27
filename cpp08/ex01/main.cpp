#include <vector>
#include <iostream>
#include "Span.hpp"

int main()
{
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		sp.addNumber(12);
	}
	catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try {
		Span sp2 = Span(3);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try {
		Span sp3 = Span(10000);
		for (int i = 0; i < 10000; ++i) {
			sp3.addNumber(i * 2);
		}
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}