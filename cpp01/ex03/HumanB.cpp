#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}

HumanB::HumanB(std::string name, Weapon &weapon) : name(name), weapon(&weapon) {}

HumanB::~HumanB() {}

void HumanB::attack()
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " is unarmed, can't attack" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
