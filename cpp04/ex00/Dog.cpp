#include "Dog.hpp"

Dog::Dog() : Animal( "Dog" ) {
	std::cout << "Dog Default constructor is called" << std::endl;
}

Dog::Dog( const Dog &ref ) : Animal( ref ) {
	std::cout << "Dog Copy constructor is called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor is called" << std::endl;
}

Dog	&Dog::operator=( const Dog &src ) {
	std::cout << "Dog Assignmet Operator is called" << std::endl;
	Animal::operator=( src );
	return *this;
}

void	Dog::makeSound( void ) const {
	std::cout << "Dogs bark..." << std::endl;
}
