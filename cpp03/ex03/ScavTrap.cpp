#include <iostream>
#include "ScavTrap.hpp"

ScavTrap:: ScavTrap() : ClapTrap("NONE") {
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << getName() << " constructed without values." << std::endl;
}

ScavTrap:: ScavTrap(std::string name) : ClapTrap(name) {
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << getName() << " constructed." << std::endl;
}

ScavTrap:: ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap " << getName() << " copy constructed." << std::endl;
}

ScavTrap& ScavTrap:: operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap " << getName() << " assigned." << std::endl;
	return *this;
}

ScavTrap:: ~ScavTrap() {
	std::cout << "ScavTrap " << getName() << " destructed." << std::endl;
}

void ScavTrap:: guardGate() {
	if (getHitPoints() > 0) {
		std::cout << "ScavTrap " << getName() << " is now in Gate Keeper mode." << std::endl;
	} else {
		std::cout << "ScavTrap " << getName() << " has no hit points left to enter Gate Keeper mode." << std::endl;
	}
}

void ScavTrap:: attack(const std::string& target) {
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ScavTrap " << getName() << " attacks " << target
				  << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	} else {
		std::cout << "ScavTrap " << getName() << " has no energy or hit points left to attack." << std::endl;
	}
}