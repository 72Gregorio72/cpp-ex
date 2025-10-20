#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
	public:
		std::string s1;
		int n;
		std::string s2;
		Data();
		Data(std::string str1, int num, std::string str2);
		~Data();
		Data(const Data& other);
		Data& operator=(const Data& other);
};

#endif