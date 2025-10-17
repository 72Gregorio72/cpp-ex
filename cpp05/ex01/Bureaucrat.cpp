#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : m_name("Default"), m_grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : m_name(name), m_grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : m_name(src.m_name), m_grade(src.m_grade)
{
	return ;
}

Bureaucrat::~Bureaucrat( void )
{
	return ;
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if (this != &rhs)
		this->m_grade = rhs.m_grade;
	return *this;
}

std::string	Bureaucrat::getName( void ) const
{
	return this->m_name;
}

int	Bureaucrat::getGrade( void ) const
{
	return this->m_grade;
}

void	Bureaucrat::incrementGrade( void )
{
	if (this->m_grade + 1 > 150)
		throw Bureaucrat::GradeTooHighException();
	this->m_grade++;
	return ;
}

void	Bureaucrat::decrementGrade( void )
{
	if (this->m_grade - 1 < 1)
		throw Bureaucrat::GradeTooLowException();
	this->m_grade--;
	return ;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return o;
}