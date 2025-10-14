#include "Character.hpp"

Character::Character(const std::string& name) : name(name) {
	for (int i = 0; i < 4; ++i) {
		inventory[i] = NULL;
	}
	std::cout << "Character " << name << " default constructor called" << std::endl;
}

Character::Character(const Character& other) : name(other.name) {
	for (int i = 0; i < 4; ++i) {
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	std::cout << "Character " << name << " copy constructor called" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; ++i) {
		delete inventory[i];
	}
	std::cout << "Character " << name << " destructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		name = other.name;
		for (int i = 0; i < 4; ++i) {
			delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	std::cout << "Character " << name << " copy assignment operator called" << std::endl;
	return *this;
}

std::string const & Character::getName() const {
	return name;
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "Cannot equip a null materia." << std::endl;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (!inventory[i]) {
			inventory[i] = m;
			std::cout << "Equipped " << m->getType() << " materia in slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << "Inventory full, cannot equip more materia." << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Invalid inventory index." << std::endl;
		return;
	}
	if (inventory[idx]) {
		std::cout << "Unequipped " << inventory[idx]->getType() << " materia from slot " << idx << "." << std::endl;
		inventory[idx] = NULL;
	} else {
		std::cout << "No materia to unequip in slot " << idx << "." << std::endl;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Invalid inventory index." << std::endl;
		return;
	}
	if (inventory[idx]) {
		inventory[idx]->use(target);
	} else {
		std::cout << "No materia in slot " << idx << " to use." << std::endl;
	}
}