#include "iter.hpp"
#include <string>
#include <vector>
#include <iostream>

void addOne(int& n) {
	n += 1;
}

void addExclamation(std::string& str) {
	str += "!";
}

void printConstInt(const int& n) {
	std::cout << n << " ";
}

int main() {
	const std::size_t length = 5;
	int array[length] = {0, 1, 2, 3, 4};

	iter(array, length, addOne);

	std::string arrayString[length] = {"hello", "world", "this", "is", "C++"};

	iter(arrayString, length, addExclamation);

	for (std::size_t i = 0; i < length; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	for (const auto& str : arrayString) {
		std::cout << str << " ";
	}
	std::cout << std::endl;

	std::vector<int> vec = {10, 20, 30, 40};
	iter(vec.data(), vec.size(), printConstInt);
	std::cout << std::endl;

	return 0;
}