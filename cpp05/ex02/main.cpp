#include "Bureaucrat.hpp"
#include <cstdlib>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	srand(time(NULL));

	Bureaucrat high("Alice", 1);
	Bureaucrat mid("Bob", 70);
	Bureaucrat low("Charlie", 150);

	ShrubberyCreationForm shrub("Garden");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Marvin");
	std::cout << high << std::endl;
	std::cout << mid << std::endl;
	std::cout << low << std::endl;

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	try { shrub.beSigned(mid); std::cout << "Bob signed Shrubbery\n"; }
	catch (std::exception &e) { std::cerr << "Bob failed to sign Shrubbery: " << e.what() << std::endl; }

	try { robot.beSigned(low); std::cout << "Charlie signed Robotomy\n"; }
	catch (std::exception &e) { std::cerr << "Charlie failed to sign Robotomy: " << e.what() << std::endl; }

	try { pardon.beSigned(high); std::cout << "Alice signed Pardon\n"; }
	catch (std::exception &e) { std::cerr << "Alice failed to sign Pardon: " << e.what() << std::endl; }

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	high.executeForm(shrub);
	mid.executeForm(robot);
	low.executeForm(pardon);

	try {
		Bureaucrat tooLowShrub("TooLowShrub", 150);
		shrub.beSigned(tooLowShrub);
		std::cout << "TooLowShrub signed Shrubbery\n";
	}
	catch (std::exception &e) { std::cerr << "TooLowShrub failed to sign Shrubbery: " << e.what() << std::endl; }

	try {
		Bureaucrat tooHighShrub("TooHighShrub", 0);
		shrub.beSigned(tooHighShrub);
		std::cout << "TooHighShrub signed Shrubbery\n";
	}
	catch (std::exception &e) { std::cerr << "TooHighShrub failed to sign Shrubbery: " << e.what() << std::endl; }

	try {
		Bureaucrat tooLowRobot("TooLowRobot", 150);
		robot.beSigned(tooLowRobot);
		std::cout << "TooLowRobot signed Robotomy\n";
	}
	catch (std::exception &e) { std::cerr << "TooLowRobot failed to sign Robotomy: " << e.what() << std::endl; }

	try {
		Bureaucrat tooHighRobot("TooHighRobot", 0);
		robot.beSigned(tooHighRobot);
		std::cout << "TooHighRobot signed Robotomy\n";
	}
	catch (std::exception &e) { std::cerr << "TooHighRobot failed to sign Robotomy: " << e.what() << std::endl; }

	try {
		Bureaucrat tooLowPardon("TooLowPardon", 150);
		pardon.beSigned(tooLowPardon);
		std::cout << "TooLowPardon signed Pardon\n";
	}
	catch (std::exception &e) { std::cerr << "TooLowPardon failed to sign Pardon: " << e.what() << std::endl; }

	try {
		Bureaucrat tooHighPardon("TooHighPardon", 0);
		pardon.beSigned(tooHighPardon);
		std::cout << "TooHighPardon signed Pardon\n";
	}
	catch (std::exception &e) { std::cerr << "TooHighPardon failed to sign Pardon: " << e.what() << std::endl; }

	return 0;
}