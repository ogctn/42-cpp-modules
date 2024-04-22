#include "FlagTrap.hpp"

FlagTrap::FlagTrap() : ClapTrap() {
	_hp = 100;
	_energy = 100;
	_ad = 30;
	std::cout << "FlagTrap default constructor is called" << std::endl;
}

FlagTrap::FlagTrap( std::string name ) : ClapTrap( name ) {
	_hp = 100;
	_energy = 100;
	_ad = 30;
	std::cout << "FlagTrap name constructor is called" << std::endl;
}

FlagTrap::FlagTrap( const FlagTrap &ref ) : ClapTrap( ref ) {
	std::cout << "FlagTrap copy constructor is called" << std::endl;
}

FlagTrap::~FlagTrap() {
	std::cout << "FlagTrap destructor is called" << std::endl;
}

FlagTrap	&FlagTrap::operator=( const FlagTrap &src ) {
	std::cout << "FlagTrap assignmet operator is called" << std::endl;
	_name = src._name;
	_hp = src._hp;
	_energy = src._energy;
	_ad = src._ad;
	return *this;
}

void	 FlagTrap::highFivesGuys() {
	std::cout << "FlagTrap " + _name + " requests a cute high-five!" << std::endl;
}
