#include <iostream>
#include "ScavTrap.hpp"

int main() {
	ScavTrap scav1("Pippo");
	ScavTrap scav2("Baudo");

	scav1.setAttackDamage(18);
	scav2.setAttackDamage(89);

	scav1.attack(scav2.getName());
	scav2.takeDamage(scav1.getAttackDamage());

	scav2.attack(scav1.getName());
	scav1.takeDamage(scav2.getAttackDamage());

	scav1.beRepaired(4);
	scav2.beRepaired(2);

	return 0;
}