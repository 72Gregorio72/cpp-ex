#include "AForm.hpp"

AForm::AForm( void ) : m_name("Default"), m_isSigned(false), m_signGrade(150), m_execGrade(150)
{
	return ;
}

AForm::AForm( std::string name, int signGrade, int execGrade ) : m_name(name), m_isSigned(false), m_signGrade(signGrade), m_execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	return ;
}

AForm::AForm( AForm const & src ) : m_name(src.m_name), m_isSigned(src.m_isSigned), m_signGrade(src.m_signGrade), m_execGrade(src.m_execGrade)
{
	return ;
}

AForm::~AForm( void )
{
	return ;
}

AForm &AForm::operator=( AForm const & rhs )
{
	if (this != &rhs)
		this->m_isSigned = rhs.m_isSigned;
	return *this;
}

std::string	AForm::getName( void ) const
{
	return this->m_name;
}

bool	AForm::getIsSigned( void ) const
{
	return this->m_isSigned;
}

int	AForm::getSignGrade( void ) const
{
	return this->m_signGrade;
}

int	AForm::getExecGrade( void ) const
{
	return this->m_execGrade;
}

void	AForm::beSigned( Bureaucrat const & b )
{
	if (b.getGrade() > this->m_signGrade)
		throw AForm::GradeTooLowException();
	this->m_isSigned = true;
	return ;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm Exception: Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm Exception: Grade is too low";
}

AForm::FormNotSignedException::FormNotSignedException() {}

AForm::FormNotSignedException::~FormNotSignedException() throw() {}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream &	operator<<( std::ostream & o, AForm const & rhs )
{
	o << "AForm " << rhs.getName() << ", sign grade " << rhs.getSignGrade() << ", exec grade " << rhs.getExecGrade() << ", is ";
	if (rhs.getIsSigned())
		o << "signed";
	else
		o << "not signed";
	return o;
}