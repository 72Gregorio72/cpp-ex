#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("NONE") {
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << getName() << " constructed without values." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << getName() << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap " << getName() << " copy constructed." << std::endl;
}

FragTrap& FragTrap:: operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << getName() << " assigned." << std::endl;
	return *this;
}

FragTrap:: ~FragTrap() {
	std::cout << "FragTrap " << getName() << " destructed." << std::endl;
}

void FragTrap:: highFivesGuys() {
	if (getHitPoints() > 0) {
		std::cout << "FragTrap " << getName() << " requested a high five!" << std::endl;
	} else {
		std::cout << "FragTrap " << getName() << " has no hit points left to request a high five." << std::endl;
	}
}