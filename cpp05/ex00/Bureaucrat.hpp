#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>

class Bureaucrat
{
	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat( void );

		Bureaucrat &operator=( Bureaucrat const & rhs );

		std::string		getName( void ) const;
		int				getGrade( void ) const;

		void			incrementGrade( void );
		void			decrementGrade( void );

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
		int					m_grade;

};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif