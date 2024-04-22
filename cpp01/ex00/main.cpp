#include "Zombie.hpp"

int	main()
{
	randomChump(std::string("z1"));
	randomChump(std::string("z2"));
	randomChump(std::string("z3"));
	Zombie *pz1, *pz2;

	pz1 = newZombie("a1");
	pz2 = newZombie("a2");
	pz1->announce();
	pz2->announce();
	delete pz1;
	delete pz2;
}
