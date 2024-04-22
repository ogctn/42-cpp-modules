#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	_name = "noname";
	_hp = 10;
	_energy = 10;
	_ad = 10;
	std::cout << "ClapTrap Default constructor is called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name( name ), _hp ( 10 ), _energy( 10 ), _ad( 10 ) {
	std::cout << "ClapTrap name constructor is called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &ref ) : 
	_name( ref._name ), _hp ( ref._hp ), _energy( ref._energy ), _ad( ref._ad ) {
	std::cout << "ClapTrap copy constructor is called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor is called" << std::endl;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &src ) {
	std::cout << "ClapTrap assignmet operator is called" << std::endl;
	_name = src._name;
	_hp = src._hp;
	_energy = src._energy;
	_ad = src._ad;
	return *this;
}

void	ClapTrap::attack( const std::string &target ) {
	if ( _hp > 0 && _energy > 0 )
		std::cout << "Claptrap " + _name + " attacks " + target + ", causing "
			<< _ad << " points of damage!" << std::endl;
	else if ( _hp > 0 && _energy <= 0 )
		std::cout << "Claptrap " + _name + " has no energy to attack " + target << std::endl;
	else
		std::cout << "Claptrap " + _name + " is dead, unable to attack!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int damage) {
	if ( _hp <= 0 && damage > 0 )
		std::cout << "Claptrap " + _name + " is already dead." << std::endl;
	else if ( _hp > 0 && damage > 0 ) {
		std::cout << "Claptrap " + _name + " has taken " << damage << " damage";
		_hp -= damage;
		if ( _hp <= 0 )
			std::cout << " and died." << std::endl;
		else
			std::cout << ". Remaining hp: " << _hp << std::endl;
	}
	else
		std::cout << "Really, is it all you can do?" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int repair ) {
	if ( _hp <= 0 ) {
		std::cout << "Claptrap " + _name + " is already dead. Unable to repair" << std::endl;
		return ;
	}
	if ( repair > 0 ) {
		_hp += repair;
		std::cout << "Claptrap " + _name + " has been repaired " << repair << " damage. "
				<< "New hp: " << _hp << std::endl;
	}
	else
		std::cout << "Claptrap " + _name + " has been repaired 0 hp, it has "<< _hp << " hp." << std::endl;
}
