#include "RPN.hpp"

RPN::RPN() : stack(){};

RPN::~RPN(){};

RPN::RPN(const RPN& other){
	stack = other.stack;
}

RPN& RPN::operator=(const RPN& other){
	if (this == &other)
		return *this;
	stack = other.stack;
	return *this;
}

double RPN::getInput(std::string s){
	std::istringstream ss(s);
	std::string token;
	double res;
	while (ss >> token){
		if (isdigit(token[0])){
			double val;
			std::istringstream(token) >> val;
			stack.push(val);
		}
		else{
			if (stack.size() < 2){
				throw RPN::EmptyStackException();
			}
			double b = stack.top();
			stack.pop();
            double a = stack.top();
			stack.pop();
            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/':
					if (a == 0){
						res = 0;
					} else {
						if (b == 0) {
							throw std::invalid_argument("Error: Division by zero.");
						}
						res = a / b;
					}
					
					break;
                default:
                    throw std::invalid_argument("Error: invalid operator.");
            }
            stack.push(res);
		}
	}
	return stack.top();
}
