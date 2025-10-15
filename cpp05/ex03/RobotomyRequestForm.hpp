#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
		void execute(Bureaucrat const & executor) const;

	private:
		std::string target;
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & rhs);

#endif