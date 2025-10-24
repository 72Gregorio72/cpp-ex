#include "ScalarConverter.hpp"

bool	ScalarConverter::isChar(std::string literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool	ScalarConverter::isInt(std::string literal)
{
	if (literal.empty())
		return false;
	if (isFloat(literal) || isDouble(literal) || isChar(literal))
		return false;
	if (literal[0] == '-' || literal[0] == '+')
	{
		if (literal.length() == 1)
			return false;
		for (size_t i = 1; i < literal.length(); i++)
		{
			if (!std::isdigit(literal[i]))
				return false;
		}
	}
	else
	{
		for (size_t i = 0; i < literal.length(); i++)
		{
			if (!std::isdigit(literal[i]))
				return false;
		}
	}
	return true;
}

bool	ScalarConverter::isFloat(std::string literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	if (literal[literal.length() - 1] != 'f')
		return false;
	if (literal.find('.') ==  std::string::npos)
		return false;
	return true;
}

bool	ScalarConverter::isDouble(std::string literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	if (literal.find('.') == std::string::npos || literal[literal.length() - 1] == 'f')
		return false;
	return true;
}

void	ScalarConverter::printChar(char c)
{
	if (std::isprint(c) && c >= 0 && c <= 127)
		std::cout << "char: '" << c << "'" << std::endl;
	else if (c >= 0 && c < 32)
		std::cout << "char: Non displayable" << std::endl;
	else if (c < 0 || c > 127)
		std::cout << "char: impossible" << std::endl;
}

void	ScalarConverter::printInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::printFloat(float f)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}

void	ScalarConverter::printDouble(double d)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(d))
		std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::convert(std::string literal)
{
	errno = 0;

	if (literal.length() > 1 && !isInt(literal) && !isFloat(literal) && !isDouble(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		printFloat(std::numeric_limits<float>::quiet_NaN());
		printDouble(std::numeric_limits<double>::quiet_NaN());
		return;
	}
	if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		printFloat(std::numeric_limits<float>::infinity());
		printDouble(std::numeric_limits<double>::infinity());
		return;
	}
	if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		printFloat(-std::numeric_limits<float>::infinity());
		printDouble(-std::numeric_limits<double>::infinity());
		return;
	}

	if (isInt(literal))
	{
		long l = std::strtol(literal.c_str(), NULL, 10);
		if (errno == ERANGE || l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			printFloat(static_cast<float>(l));
			printDouble(static_cast<double>(l));
			return;
		}
	}
	else if (isFloat(literal))
	{
		float f = std::strtof(literal.c_str(), NULL);
		if (errno == ERANGE || f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			printDouble(static_cast<double>(f));
			return;
		}
	}
	else if (isDouble(literal))
	{
		double d = std::strtod(literal.c_str(), NULL);
		if (errno == ERANGE || d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}
	if (isChar(literal))
	{
		char c = literal[0];
		printChar(c);
		printInt(static_cast<int>(c));
		printFloat(static_cast<float>(c));
		printDouble(static_cast<double>(c));
	}
	else if (isInt(literal))
	{
		int i = std::atoi(literal.c_str());
		printChar(static_cast<char>(i));
		printInt(i);
		printFloat(static_cast<float>(i));
		printDouble(static_cast<double>(i));
	}
	else if (isFloat(literal))
	{
		float f = std::strtof(literal.c_str(), NULL);
		printChar(static_cast<char>(f));
		printInt(static_cast<int>(f));
		printFloat(f);
		printDouble(static_cast<double>(f));
	}
	else if (isDouble(literal))
	{
		double d = std::strtod(literal.c_str(), NULL);
		printChar(static_cast<char>(d));
		printInt(static_cast<int>(d));
		printFloat(static_cast<float>(d));
		printDouble(d);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & src) { (void)src; }

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs) { (void)rhs; return *this; }

ScalarConverter::~ScalarConverter() {}