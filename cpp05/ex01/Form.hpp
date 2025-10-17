#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form( void );
		Form( std::string name, int signGrade, int execGrade );
		Form( Form const & src );
		~Form( void );

		Form &operator=( Form const & rhs );

		std::string		getName( void ) const;
		bool			getIsSigned( void ) const;
		int				getSignGrade( void ) const;
		int				getExecGrade( void ) const;

		void			beSigned( Bureaucrat const & b );

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string const	m_name;
		bool				m_isSigned;
		int	const			m_signGrade;
		int	const			m_execGrade;

};

std::ostream &	operator<<( std::ostream & o, Form const & rhs );

#endif