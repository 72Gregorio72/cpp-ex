#include "RPN.hpp"

bool parsing(std::string s){
	for (size_t i = 0; i < s.length(); i++) {
		if (!isdigit(s[i]) && s[i] != ' ' && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
			return false;
	}
	{
		size_t i = 0;
		int nums = 0;
		int ops = 0;
		while (i < s.size()) {
			while (i < s.size() && s[i] == ' ') ++i;
			if (i >= s.size()) break;
			size_t j = i;
			while (j < s.size() && s[j] != ' ') ++j;
			std::string token = s.substr(i, j - i);
			i = j;
			if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
				++ops;
			} else {
				for (size_t k = 0; k < token.size(); ++k) {
					if (!std::isdigit(static_cast<unsigned char>(token[k])))
						return false;
				}
				++nums;
			}
		}
		if (nums != ops + 1)
			return false;
	}
	return true;
}

int main(int ac, char**av){
	if (ac != 2){
		std::cerr << "Usage: ./RPN \"expression\"\n";
		return 1;
	}
	std::string expression = av[1];
	if (!parsing(expression)){
		std::cerr << "Error: invalid expression.\n";
		return 1;
	}
	RPN rpn;
	try {
		double result = rpn.getInput(expression);
		std::cout << result << '\n';
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}