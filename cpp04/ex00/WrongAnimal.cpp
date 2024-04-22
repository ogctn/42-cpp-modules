#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type( "unknown_type" ) {
	std::cout << "WrongAnimal Default constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type) : _type( type ) {
	std::cout << "WrongAnimal type constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &ref ) : _type( ref._type ) {
	std::cout << "WrongAnimal copy constructor is called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor is called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=( const WrongAnimal &src ) {
	std::cout << "WrongAnimal assignmet operator is called" << std::endl;
	_type = src._type;
	return *this;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal generic sound..." << std::endl;
}

std::string	WrongAnimal::getType() const {
	return _type;
}
