#include "Data.hpp"

Data::Data() : s1(""), n(0), s2("") {}

Data::~Data() {}

Data::Data(const Data& other) : s1(other.s1), n(other.n), s2(other.s2) {}

Data& Data::operator=(const Data& other) {
	if (this != &other) {
		s1 = other.s1;
		n = other.n;
		s2 = other.s2;
	}
	return *this;
}

Data::Data(std::string str1, int num, std::string str2) : s1(str1), n(num), s2(str2) {}