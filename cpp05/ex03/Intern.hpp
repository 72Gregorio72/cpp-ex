#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern( void );
		Intern( Intern const & src );
		~Intern( void );

		Intern &operator=( Intern const & rhs );

		AForm* makeForm(std::string formName, std::string target);

		class UnknownFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		static const std::string formNames[3];
		AForm* (Intern::*formCreators[3])(std::string target);
		AForm* createPresidentialPardonForm(std::string target);
		AForm* createRobotomyRequestForm(std::string target);
		AForm* createShrubberyCreationForm(std::string target);
};

#endif