#include "Character.hpp"

Character::Character( void ) : _name( "default" ) {
	for ( int i = 0; i < 4; i++ ) {
		_inventory[i] = NULL;
	}
}

Character::Character( std::string name ) : _name( name ) {
	for ( int i = 0; i < 4; i++ ) {
		_inventory[i] = NULL;
	}
}

Character::Character( const Character &ref ) : _name( ref._name ) {
	for ( int i = 0; i < 4; i++ ) {
		_inventory[i] = ref._inventory[i];
	}
}

Character::~Character( void ) {
	for ( int i = 0; i < 4; i++ ) {
		if ( _inventory[i] != NULL )
			delete _inventory[i];
	}
}

Character &Character::operator=( const Character &src ) {
	if ( this != &src ) {
		_name = src._name;
		for ( int i = 0; i < 4; i++ ) {
			_inventory[i] = src._inventory[i];
		}
	}
	return *this;
}

std::string const	&Character::getName( void ) const {
	return _name;
}

void	Character::equip( AMateria* m ) {
	for ( int i = 0; m && i < 4; i++ ) {
		if ( _inventory[i] == m ) {
			for ( ; i < 4; i++ ) {
				if ( _inventory[i] == NULL ) {
					_inventory[i] = m->clone();
					std::cout << m->getType() + " is equipped to slot [ " << i << " ]" << std::endl;
					break;	
				}
			}
			break;
		}
		else if ( _inventory[i] == NULL ) {
			_inventory[i] = m;
			std::cout << m->getType() + " is equipped to slot [ " << i << " ]" << std::endl;
			break;
		}
	}
}

void	Character::unequip( int idx ) {
	if ( ( idx > 0 && idx < 4 ) && _inventory[idx] != NULL )
		_inventory[idx] = NULL;
}

void	Character::use( int idx, ICharacter& target ) {
	if ( ( idx >= 0 && idx < 4) && _inventory[idx] != NULL )
		_inventory[idx]->use( target );
}

void	Character::show_inventory( void ) const {
	std::cout << "-_-_-_-_-_-_-_-_-_-_-_-_" << std::endl;
	std::cout << "[Number]    [Type]" << std::endl;
	for ( int i = 0; i < 4; i++ ) {
		if ( _inventory[i] != NULL ) {
			std::cout << "    " << i << "\t    " << _inventory[i]->getType() << std::endl;
		}
		else if ( _inventory[i] == NULL )
			std::cout << "    " << i << "\t    " << "NULL" << std::endl;
	}
	std::cout << "-_-_-_-_-_-_-_-_-_-_-_-_" << std::endl;
}

