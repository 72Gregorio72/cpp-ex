#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
		void execute(Bureaucrat const & executor) const;

	private:
		std::string target;
};

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & rhs);

#endif