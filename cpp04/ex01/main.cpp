#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* animals[10];
	for (int i = 0; i < 10; ++i) {
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 10; ++i) {
		animals[i]->makeSound();
	}
	for (int i = 0; i < 10; ++i) {
		delete animals[i];
	}

	return 0;
}