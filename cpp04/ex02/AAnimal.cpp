#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type( "unknown_type" ) {
	std::cout << "AAnimal Default constructor is called" << std::endl;
}

AAnimal::AAnimal( std::string type) : _type( type ) {
	std::cout << "AAnimal type constructor is called" << std::endl;
}

AAnimal::AAnimal( const AAnimal &ref ) : _type( ref._type ) {
	std::cout << "AAnimal copy constructor is called" << std::endl;
}

AAnimal::~AAnimal( void ) {
	std::cout << "AAnimal destructor is called" << std::endl;
}

AAnimal	&AAnimal::operator=( const AAnimal &src ) {
	std::cout << "AAnimal assignmet operator is called" << std::endl;
	_type = src._type;
	return *this;
}

std::string	AAnimal::getType( void ) const {
	return _type;
}

