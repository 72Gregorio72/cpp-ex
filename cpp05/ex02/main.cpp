#include "Bureaucrat.hpp"
#include <cstdlib>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	srand(time(NULL));

	Bureaucrat high("Alice", 1);      // Highest grade
	Bureaucrat mid("Bob", 70);        // Middle grade
	Bureaucrat low("Charlie", 150);   // Lowest grade

	ShrubberyCreationForm shrub("Garden");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Marvin");

	// Print initial state
	std::cout << high << std::endl;
	std::cout << mid << std::endl;
	std::cout << low << std::endl;

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	// Try signing forms with different bureaucrats
	std::cout << "\n--- Signing Forms ---\n";
	try { shrub.beSigned(mid); std::cout << "Bob signed Shrubbery\n"; }
	catch (std::exception &e) { std::cerr << "Bob failed to sign Shrubbery: " << e.what() << std::endl; }

	try { robot.beSigned(low); std::cout << "Charlie signed Robotomy\n"; }
	catch (std::exception &e) { std::cerr << "Charlie failed to sign Robotomy: " << e.what() << std::endl; }

	try { pardon.beSigned(high); std::cout << "Alice signed Pardon\n"; }
	catch (std::exception &e) { std::cerr << "Alice failed to sign Pardon: " << e.what() << std::endl; }

	// Print forms after signing
	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	// Try executing forms with different bureaucrats
	std::cout << "\n--- Executing Forms ---\n";
	high.executeForm(shrub);
	mid.executeForm(robot);
	low.executeForm(pardon);

	return 0;
}