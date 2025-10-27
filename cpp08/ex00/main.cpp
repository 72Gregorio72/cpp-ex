#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(){
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i * 10);
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(vec, 50);
		std::cout << "Found: " << *it << std::endl;
		it = easyfind(vec, 55);
		std::cout << "Found: " << *it << std::endl;
	} catch (const Easyfind::IntegerNotFoundException &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}