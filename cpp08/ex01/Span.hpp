#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>

class Span{
	public:
		Span();
		~Span();
		Span(unsigned int n);
		Span &operator=(const Span &other);
		Span(const Span &other);
		int getSpan();
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		class OutOfBoundException: public std::exception{
			public:
				const char *what() const throw() {
					return "index Out Of Bounds";
				}
		};
		class VectorTooSmallException: public std::exception{
			public:
				const char *what() const throw() {
					return "Vector too small";
				}
		};
	private:
		int n;
		std::vector<int> vec;
};

#endif