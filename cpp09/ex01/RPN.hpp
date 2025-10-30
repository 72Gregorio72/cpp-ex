#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

class RPN{
	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		double getInput(std::string expression);
		class EmptyStackException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: Stack is empty.";
				}
		};
	private:
		std::stack<double> stack;
};

#endif