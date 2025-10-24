#include "Form.hpp"

Form::Form( void ) : m_name("Default"), m_isSigned(false), m_signGrade(150), m_execGrade(150)
{
	return ;
}

Form::Form( std::string name, int signGrade, int execGrade ) : m_name(name), m_isSigned(false), m_signGrade(signGrade), m_execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	return ;
}

Form::Form( Form const & src ) : m_name(src.m_name), m_isSigned(src.m_isSigned), m_signGrade(src.m_signGrade), m_execGrade(src.m_execGrade)
{
	return ;
}

Form::~Form( void )
{
	return ;
}

Form &Form::operator=( Form const & rhs )
{
	if (this != &rhs)
		this->m_isSigned = rhs.m_isSigned;
	return *this;
}

std::string	Form::getName( void ) const
{
	return this->m_name;
}

bool	Form::getIsSigned( void ) const
{
	return this->m_isSigned;
}

int	Form::getSignGrade( void ) const
{
	return this->m_signGrade;
}

int	Form::getExecGrade( void ) const
{
	return this->m_execGrade;
}

void	Form::beSigned( Bureaucrat const & b )
{
	if (b.getGrade() > this->m_signGrade)
		throw Form::GradeTooLowException();
	this->m_isSigned = true;
	return ;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form Exception: Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form Exception: Grade is too low";
}

std::ostream &	operator<<( std::ostream & o, Form const & rhs )
{
	o << "Form " << rhs.getName() << ", sign grade " << rhs.getSignGrade() << ", exec grade " << rhs.getExecGrade() << ", is ";
	if (rhs.getIsSigned())
		o << "signed";
	else
		o << "not signed";
	return o;
}