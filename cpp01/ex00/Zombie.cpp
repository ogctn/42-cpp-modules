#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Created a zombie with no name" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Created zombie -:: " << this->_name << " ::-" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destroyed zombie -:: " << this->_name << " ::-" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
