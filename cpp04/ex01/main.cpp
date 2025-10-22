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
		if (const Dog* d = dynamic_cast<const Dog*>(animals[i])) {
			if (d->getBrain())
				std::cout << d->getBrain()->getIdea(0) << std::endl;
		} else if (const Cat* c = dynamic_cast<const Cat*>(animals[i])) {
			if (c->getBrain())
				std::cout << c->getBrain()->getIdea(0) << std::endl;
		}
	}
	for (int i = 0; i < 10; ++i) {
		delete animals[i];
	}

	return 0;
}