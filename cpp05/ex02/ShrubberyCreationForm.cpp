#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other), target(other.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->target = rhs.target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();

	std::ofstream file;
	file.open((this->target + "_shrubbery").c_str());
	if (file.is_open()) {
		file << "       _-_\n"
		        "    /~~   ~~\\\n"
		        " /~~         ~~\\\n"
		        "{               }\n"
		        " \\  _-     -_  /\n"
		        "   ~  \\\\ //  ~\n"
		        "_- -   | | _- _\n"
		        "  _ -  | |   -_\n"
		        "      // \\\\\n";
		file.close();
	}
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs)
{
	o << static_cast<AForm const &>(rhs);
	return o;
}