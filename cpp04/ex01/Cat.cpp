#include "Cat.hpp"

Cat::Cat( void ) : Animal( "Cat" ) {
	std::cout << "Cat Default constructor is called" << std::endl;
	_brain = new Brain;
}

Cat::Cat( const Cat &ref ) : Animal( ref ) {
	std::cout << "Cat Copy constructor is called" << std::endl;
	_brain = new Brain;
	for ( int i = 0; i < 100; i++ ) {
		_brain->set_idea( i, ref._brain->get_idea( i ) );
	}
}

Cat::~Cat( void ) {
	delete _brain;
	std::cout << "Cat destructor is called" << std::endl;
}

Cat	&Cat::operator=( const Cat &src ) {
	std::cout << "Cat Assignmet Operator is called" << std::endl;
	if ( this != &src ) {
		Animal::operator=( src );
		for ( int i = 0; i < 100; i++ ) {
			_brain->set_idea( i, src._brain->get_idea( i ) );
		}
	}
	return *this;
}

void	Cat::makeSound( void ) const {
	std::cout << "Cats don't bark..." << std::endl;
}

std::string	Cat::get_idea( unsigned int idx ) const {
	std::ostringstream ss;

	ss << getType() << " 's idea is: " + _brain->get_idea( idx );
	return ss.str();
}
