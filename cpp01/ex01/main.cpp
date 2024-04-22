#include "Zombie.hpp"

int	main()
{
	int N = 4;
	std::string name = "zommm";
	Zombie *pz;
	
	pz = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		pz->announce();
	pz[N].announce();
	delete []pz;
}
