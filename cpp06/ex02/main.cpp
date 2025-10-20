#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void) {
	std::srand(std::time(0));
	int randNum = std::rand() % 3;
	switch (randNum) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown Type" << std::endl;
}

void identify(Base& p) {
	A* aPtr = dynamic_cast<A*>(&p);
	if (aPtr) {
		std::cout << "A" << std::endl;
		return;
	}
	B* bPtr = dynamic_cast<B*>(&p);
	if (bPtr) {
		std::cout << "B" << std::endl;
		return;
	}
	C* cPtr = dynamic_cast<C*>(&p);
	if (cPtr) {
		std::cout << "C" << std::endl;
		return;
	}
	std::cout << "Unknown Type" << std::endl;
}

int main(){
	Base* basePtr = generate();
	identify(basePtr);
	identify(*basePtr);
	delete basePtr;
}