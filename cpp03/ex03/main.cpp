#include <iostream>
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap diamond1("Pippo");
	DiamondTrap diamond2("Baudo");
	diamond1.setAttackDamage(18);
	diamond2.setAttackDamage(89);
	diamond1.attack(diamond2.getName());
	diamond2.takeDamage(diamond1.getAttackDamage());
	diamond2.attack(diamond1.getName());
	diamond1.takeDamage(diamond2.getAttackDamage());

	return 0;
}