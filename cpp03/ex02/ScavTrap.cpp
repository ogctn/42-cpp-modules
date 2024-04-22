#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _gate( false ) {
	_hp = 100;
	_energy = 50;
	_ad = 20;
	std::cout << "ScavTrap default constructor is called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ), _gate( false ) {
	_hp = 100;
	_energy = 50;
	_ad = 20;
	std::cout << "ScavTrap name constructor is called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &ref ) : ClapTrap( ref ), _gate( ref._gate ) {
	std::cout << "ScavTrap copy constructor is called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor is called" << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &src ) {
	std::cout << "ScavTrap assignmet operator is called" << std::endl;
	_name = src._name;
	_hp = src._hp;
	_energy = src._energy;
	_ad = src._ad;
	_gate = src._gate;
	return *this;
}

void    ScavTrap::guardGate() {
	_gate = !_gate;
	if ( _gate )
		std::cout << "ScavTrap " + _name + " is now in Gate keeper mode" << std::endl;
	else
		std::cout << "ScavTrap " + _name + " is no longer in Gate keeper mode" << std::endl;
}

void    ScavTrap::attack( const std::string &target ) {
	if ( _hp > 0 && _energy > 0 )
		std::cout << "ScavTrap " + _name + " attacks " + target + ", causing "
			<< _ad << " points of damage!" << std::endl;
	else if ( _hp > 0 && _energy <= 0 )
		std::cout << "ScavTrap " + _name + " has no energy to attack " + target << std::endl;
	else
		std::cout << "ScavTrap " + _name + " is dead, unable to attack!" << std::endl;
}
