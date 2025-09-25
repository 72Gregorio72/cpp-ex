#include <iostream>
#include "HumanA.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;

	public:
		HumanB(std::string name);
		~HumanB();
		HumanB(std::string name, Weapon &weapon);
		void attack();
		void setWeapon(Weapon &weapon);
};