#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm:: RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
	this->target = "default";
}

RobotomyRequestForm:: RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	this->target = target;
}

RobotomyRequestForm:: RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other) {
	this->target = other.target;
}

RobotomyRequestForm:: ~RobotomyRequestForm() {
	return ;
}

RobotomyRequestForm &RobotomyRequestForm:: operator=(RobotomyRequestForm const &rhs) {
	if (this != &rhs)
		this->target = rhs.target;
	return *this;
}

void RobotomyRequestForm:: execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << "Bzzzzzzzzzzzzzzzzz" << std::endl;
	if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & rhs)
{
    o << static_cast<AForm const &>(rhs);
    return o;
}