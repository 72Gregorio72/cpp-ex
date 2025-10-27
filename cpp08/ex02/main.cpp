#include <vector>
#include <iostream>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "---- Second test ----" << std::endl;

	MutantStack<std::string> mstackStr;
	mstackStr.push("Hello");
	mstackStr.push("World");
	std::cout << mstackStr.top() << std::endl;
	mstackStr.pop();
	std::cout << mstackStr.size() << std::endl;
	mstackStr.push("C++");
	mstackStr.push("is");
	mstackStr.push("awesome!");
	MutantStack<std::string>::iterator itStr = mstackStr.begin();
	MutantStack<std::string>::iterator iteStr = mstackStr.end();
	while (itStr != iteStr) {
		std::cout << *itStr << std::endl;
		++itStr;
	}
	return 0;
}