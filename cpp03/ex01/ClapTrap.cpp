#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("NONE"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " constructed without values." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name),
	  hitPoints(other.hitPoints),
	  energyPoints(other.energyPoints),
	  attackDamage(other.attackDamage) {
	std::cout << "ClapTrap " << name << " copy constructed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap " << name << " assigned." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destructed." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		--energyPoints;
		std::cout << "ClapTrap " << name << " attacks " << target
				  << ", causing " << attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " has no energy or hit points left to attack." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints <= amount) {
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " takes " << amount
				  << " points of damage and is now destroyed!" << std::endl;
	} else {
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount
				  << " points of damage, remaining hit points: " << hitPoints << "." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0) {
		--energyPoints;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " is repaired by " << amount
				  << " points, new hit points: " << hitPoints << "." << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " has no energy or hit points left to be repaired." << std::endl;
	}
}

std::string ClapTrap::getName() const {
	return name;
}

unsigned int ClapTrap::getHitPoints() const {
	return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	return attackDamage;
}

void ClapTrap::setName(const std::string& name) {
	this->name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
	this->attackDamage = attackDamage;
}