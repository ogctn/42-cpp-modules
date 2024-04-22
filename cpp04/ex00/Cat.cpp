#include "Cat.hpp"

Cat::Cat() : Animal( "Cat" ) {
	std::cout << "Cat Default constructor is called" << std::endl;
}

Cat::Cat( const Cat &ref ) : Animal( ref ) {
	std::cout << "Cat Copy constructor is called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor is called" << std::endl;
}

Cat	&Cat::operator=( const Cat &src ) {
	std::cout << "Cat Assignmet Operator is called" << std::endl;
	Animal::operator=( src );
	return *this;
}

void	Cat::makeSound( void ) const{
	std::cout << "Cats don't bark..." << std::endl;
}
