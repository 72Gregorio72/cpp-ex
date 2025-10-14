#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		materia[i] = NULL;
	}
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; ++i) {
		if (other.materia[i])
			materia[i] = other.materia[i]->clone();
		else
			materia[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		delete materia[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			delete materia[i];
			if (other.materia[i])
				materia[i] = other.materia[i]->clone();
			else
				materia[i] = NULL;
		}
	}
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		std::cout << "Cannot learn a null materia." << std::endl;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (!materia[i]) {
			materia[i] = m;
			std::cout << "Learned " << m->getType() << " materia in slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource full, cannot learn more materia." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; ++i) {
		if (materia[i] && materia[i]->getType() == type) {
			std::cout << "Creating " << type << " materia." << std::endl;
			return materia[i]->clone();
		}
	}
	std::cout << "Materia of type " << type << " not found." << std::endl;
	return NULL;
}