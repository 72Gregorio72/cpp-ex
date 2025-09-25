#include <iostream>
#include "Zombie.h"
#include "Zombie.hpp"

int main() {
    Zombie* zombie1 = newZombie("Zombie1");
    zombie1->announce();

    randomChump("Zombie2");

	Zombie* horde = zombieHorde(3, "HordeZombie");
	for (int i = 0; i < 3; ++i) {
		horde[i].announce();
	}
	delete[] horde;

    delete zombie1;
    return 0;
}	