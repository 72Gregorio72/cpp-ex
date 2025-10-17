#include "PresidentialPardonForm.hpp"

PresidentialPardonForm:: PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
	this->target = "default";
}

PresidentialPardonForm:: PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
	this->target = target;
}

PresidentialPardonForm:: PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other) {
	this->target = other.target;
}

PresidentialPardonForm:: ~PresidentialPardonForm() {
	return ;
}

PresidentialPardonForm &PresidentialPardonForm:: operator=(PresidentialPardonForm const &rhs) {
	if (this != &rhs)
		this->target = rhs.target;
	return *this;
}

void PresidentialPardonForm:: execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & rhs)
{
    o << static_cast<AForm const &>(rhs);
    return o;
}