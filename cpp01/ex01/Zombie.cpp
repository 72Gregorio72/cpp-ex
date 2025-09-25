#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() : _name("") {}

Zombie::Zombie(std::string name) : _name(name) {}

void Zombie::setName(std::string name) {
    _name = name;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << _name << " is destroyed." << std::endl;
}

void Zombie::announce(void) {
    std::cout  << _name << ": BraiiiiiiinnnzzzZ..."<< std::endl;
}
