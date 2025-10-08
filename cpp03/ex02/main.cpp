#include <iostream>
#include "FragTrap.hpp"

int main() {
	FragTrap frag1("Pippo");
	FragTrap frag2("Baudo");

	frag1.attack(frag2.getName());
	frag2.takeDamage(frag1.getAttackDamage());

	frag2.attack(frag1.getName());
	frag1.takeDamage(frag2.getAttackDamage());

	frag1.beRepaired(4);
	frag2.beRepaired(2);

	return 0;
}