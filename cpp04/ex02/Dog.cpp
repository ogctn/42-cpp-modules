#include "Dog.hpp"

Dog::Dog( void ) : AAnimal( "Dog" ) {
	std::cout << "Dog Default constructor is called" << std::endl;
	_brain = new Brain;
}

Dog::Dog( const Dog &ref ) : AAnimal( ref ) {
	std::cout << "Dog Copy constructor is called" << std::endl;
	_brain = new Brain;
	for ( int i = 0; i < 100; i++ ) {
		_brain->set_idea(i, ref._brain->get_idea( i ) );
	}
}

Dog::~Dog( void ) {
	delete _brain;
	std::cout << "Dog destructor is called" << std::endl;
}

Dog	&Dog::operator=( const Dog &src ) {
	std::cout << "Dog Assignmet Operator is called" << std::endl;
	if ( this != &src ) {
		AAnimal::operator=( src );
		for ( int i = 0; i < 100; i++ ) {
			_brain->set_idea( i, src._brain->get_idea( i ) );
		}
	}
	return *this;
}

void	Dog::makeSound( void ) const {
	std::cout << "Dogs bark..." << std::endl;
}

std::string	Dog::get_idea( unsigned int idx ) const {
	std::ostringstream ss;

	ss << getType() << " 's idea is: " + _brain->get_idea( idx );
	return ss.str();
}
