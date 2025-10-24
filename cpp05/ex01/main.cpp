#include "Bureaucrat.hpp"
#include <cstdlib>
#include "Form.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <Name> <Bureaucrat grade> <Form sign grade>" << std::endl;
		return 1;
	}
	try
	{
		int bGrade = std::atoi(av[2]);
		int fGrade = std::atoi(av[3]);
		Bureaucrat b("Bureaucrat", bGrade);
		Form f(av[1], fGrade, fGrade);
		std::cout << f << std::endl;
		f.beSigned(b);
		std::cout << f << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}