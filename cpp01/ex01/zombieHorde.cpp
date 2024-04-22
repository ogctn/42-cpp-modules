#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *pz = new Zombie[N];

	for(int i = 0; i < N; i++)
		pz[i].set_name(name);
	return (pz);
}
