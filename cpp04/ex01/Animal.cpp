#include "Animal.hpp"

Animal::Animal( void ) : _type( "unknown_type" ) {
	std::cout << "Animal Default constructor is called" << std::endl;
}

Animal::Animal( std::string type) : _type( type ) {
	std::cout << "Animal type constructor is called" << std::endl;
}

Animal::Animal( const Animal &ref ) : _type( ref._type ) {
	std::cout << "Animal copy constructor is called" << std::endl;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor is called" << std::endl;
}

Animal	&Animal::operator=( const Animal &src ) {
	std::cout << "Animal assignmet operator is called" << std::endl;
	_type = src._type;
	return *this;
}

void	Animal::makeSound( void ) const {
	std::cout << "Animal generic sound..." << std::endl;
}

std::string	Animal::getType( void ) const {
	return _type;
}

