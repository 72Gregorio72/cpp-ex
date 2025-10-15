#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
		void execute(Bureaucrat const & executor) const;

	private:
		std::string target;
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs);

#endif