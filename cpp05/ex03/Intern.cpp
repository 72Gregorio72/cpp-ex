#include "Intern.hpp"

const std::string Intern::formNames[3] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

Intern::Intern(void) {
	this->formCreators[0] = &Intern::createPresidentialPardonForm;
	this->formCreators[1] = &Intern::createRobotomyRequestForm;
	this->formCreators[2] = &Intern::createShrubberyCreationForm;
}

Intern::Intern(Intern const &src) {
	(void)src;
}

Intern::~Intern(void) {}

Intern &Intern::operator=(Intern const &rhs) {
	(void)rhs;
	return *this;
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	throw Intern::UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw() {
	return "Intern Exception: Unknown form name";
}
