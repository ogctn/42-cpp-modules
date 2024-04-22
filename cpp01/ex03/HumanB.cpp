#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) , _weapon(NULL)
{
	std::cout << "HumanB " << this->_name << " is created." << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->_name << " is destroyed." << std::endl;
}

void	HumanB::setWeapon(Weapon & weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack() const
{
	if (this->_weapon == NULL || this->_weapon->getType().empty())
		std::cout << this->_name << " has no weapon " << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
