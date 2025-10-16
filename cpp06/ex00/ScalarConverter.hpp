#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cfloat>
# include <cmath>
# include <limits>
# include <iomanip>
# include <cerrno>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter & operator=(ScalarConverter const & rhs);
		~ScalarConverter();

		static bool	isChar(std::string literal);
		static bool	isInt(std::string literal);
		static bool	isFloat(std::string literal);
		static bool	isDouble(std::string literal);
		static void	printChar(char c);
		static void	printInt(int i);
		static void	printFloat(float f);
		static void	printDouble(double d);

	public:
		static void	convert(std::string literal);
};

#endif