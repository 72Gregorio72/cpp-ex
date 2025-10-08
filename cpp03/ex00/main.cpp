#include <iostream>
#include "ClapTrap.hpp"

int main() {
	ClapTrap clap1("Pippo");
	ClapTrap clap2("Baudo");

	clap1.setAttackDamage(18);
	clap2.setAttackDamage(89);

	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAttackDamage());

	clap2.attack(clap1.getName());
	clap1.takeDamage(clap2.getAttackDamage());

	clap1.beRepaired(4);
	clap2.beRepaired(2);

	return 0;
}