#include "Bureaucrat.hpp"
#include <cstdlib>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		try{
			std::string name = av[1];
			int grade = std::atoi(av[2]);
			Bureaucrat b(name, grade);
			std::cout << b << std::endl;
			b.incrementGrade();
			std::cout << b << std::endl;
			b.decrementGrade();
			std::cout << b << std::endl;
			b.decrementGrade();
			std::cout << b << std::endl;
		} catch (std::exception & e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	else
		std::cout << "Usage: ./bureaucrat <name> <grade>" << std::endl;
}