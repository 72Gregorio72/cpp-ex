#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <climits>
#include <iterator>

Span::Span() : n(0) {}

Span::~Span() {}

Span::Span(const Span& other) : n(other.n), vec(other.vec) {}

Span& Span::operator=(const Span &other){
	if (this != &other) {
		n = other.n;
		vec = other.vec;
	}
	return *this;
}

Span::Span(unsigned int n) : n(n){};

int Span::getSpan(){
	return n;
}

void Span::addNumber(int value){
	if (vec.size() >= static_cast<size_t>(n))
		throw Span::OutOfBoundException();
	vec.push_back(value);
}

int Span::shortestSpan(){
	if (vec.size() < 2)
		throw Span::VectorTooSmallException();

    std::sort(vec.begin(), vec.end());
	std::vector<int>::const_iterator prev = vec.begin();
	std::vector<int>::const_iterator curr = vec.begin() + 1;

    int minDiff = INT_MAX;
    for (; curr != vec.end(); ++curr, ++prev) {
        int diff = *curr - *prev;
        if (diff < minDiff)
            minDiff = diff;
    }

    return minDiff;
}

int Span::longestSpan(){
	if (vec.size() < 2)
		throw Span::VectorTooSmallException();
	
	std::sort(vec.begin(), vec.end());

	return vec.back() - vec.front();
}