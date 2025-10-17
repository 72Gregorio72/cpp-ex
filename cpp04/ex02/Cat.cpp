#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "miao" << std::endl;
}