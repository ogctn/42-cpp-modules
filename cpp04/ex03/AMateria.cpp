#include "AMateria.hpp"

AMateria::AMateria( void ) : _type( "default" ) {
}

AMateria::AMateria( std::string const &type ) : _type( type ){
}

AMateria::AMateria( const AMateria &ref ) : _type( ref._type ) {
}

AMateria::~AMateria( void ) {
}

AMateria &AMateria::operator=( const AMateria &src ) {
	if ( this != &src ) {
		_type = src._type;
	}
	return *this;
}

std::string const &AMateria::getType( void ) const {
	return _type;
}

void AMateria::use( ICharacter& target ) {
	( void ) target;
}
