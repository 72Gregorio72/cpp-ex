#include "iter.hpp"

void addOne(int& n) {
	n += 1;
}

int main() {
	const std::size_t length = 5;
	int array[length] = {0, 1, 2, 3, 4};

	iter(array, length, addOne);

	for (std::size_t i = 0; i < length; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}