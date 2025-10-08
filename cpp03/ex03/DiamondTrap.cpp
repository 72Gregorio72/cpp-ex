#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap:: DiamondTrap() : ClapTrap("NONE_clap_name"), name("NONE") {
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(50);
	FragTrap::setAttackDamage(30);
	std::cout << "DiamondTrap " << name << " constructed without values." << std::endl;
}

DiamondTrap:: DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name) {
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(50);
	FragTrap::setAttackDamage(30);
	std::cout << "DiamondTrap " << name << " constructed." << std::endl;
}

DiamondTrap:: DiamondTrap(const DiamondTrap& other) 
	: ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name) {
	std::cout << "DiamondTrap " << name << " copy constructed." << std::endl;
}

DiamondTrap& DiamondTrap:: operator=(const DiamondTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		name = other.name;
	}
	std::cout << "DiamondTrap " << name << " assigned." << std::endl;
	return *this;
}

DiamondTrap:: ~DiamondTrap() {
	std::cout << "DiamondTrap " << name << " destructed." << std::endl;
}

void DiamondTrap:: whoAmI() {
	if (FragTrap::getHitPoints() > 0) {
		std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::getName() << "." << std::endl;
	} else {
		std::cout << "DiamondTrap " << name << " has no hit points left to reveal its identity." << std::endl;
	}
}