#include "Bureaucrat.hpp"
#include <cstdlib>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	AForm* shrubbery = NULL;
	AForm* robotomy = NULL;
	AForm* pardon = NULL;

	try {
		shrubbery = intern.makeForm("shrubbery creation", "Garden");
	} catch (const std::exception& e) {
		std::cerr << "Error creating ShrubberyCreationForm: " << e.what() << std::endl;
	}

	try {
		robotomy = intern.makeForm("robotomy request", "Bender");
	} catch (const std::exception& e) {
		std::cerr << "Error creating RobotomyRequestForm: " << e.what() << std::endl;
	}

	try {
		pardon = intern.makeForm("presidential pardon", "Alice");
	} catch (const std::exception& e) {
		std::cerr << "Error creating PresidentialPardonForm: " << e.what() << std::endl;
	}

	if (shrubbery) delete shrubbery;
	if (robotomy) delete robotomy;
	if (pardon) delete pardon;
}