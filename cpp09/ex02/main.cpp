#include "PmergeMe.hpp"

std::string fillString(int ac, char **av){
	std::string input;
	for (int i = 1; i < ac; i++) {
		input += av[i];
		if (i < ac - 1) {
			input += " ";
		}
	}
	return input;
}

int main(int ac, char **av){
	PmergeMe p;
	std::string input = fillString(ac, av);

	std::cout << input << std::endl;
	if (!p.fillContainer(input)) {
		return 1;
	}

	p.sortContainers();

	p.printDeque();
	p.printVector();
}