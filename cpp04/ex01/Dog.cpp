#include "Dog.hpp"

Dog::Dog() : Animal() {
	type = "Dog";
	brain = new Brain();
	brain->setIdea(0, "palla");
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	brain = new Brain(*other.brain);
	brain->setIdea(0, "palla");
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		*brain = *other.brain;
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "bau" << std::endl;
}

Brain* Dog::getBrain() const {
	return brain;
}