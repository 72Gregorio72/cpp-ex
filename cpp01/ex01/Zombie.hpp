#include <iostream>
#include <string>

class Zombie {
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce(void);
		void setName(std::string name);

	private:
		std::string _name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);