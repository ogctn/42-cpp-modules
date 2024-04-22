#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed() : _fixed_point_val( 0 ) {
	std::cout << "Default Construcor called from Fixed." << std::endl;
}

Fixed::Fixed( const Fixed &copy_from ) {
	std::cout << "Copy construcor called from Fixed." << std::endl;
	*this = copy_from;
}

Fixed &Fixed::operator=( const Fixed &to_assign) {
	std::cout << "Copy assignment operator called from Fixed." << std::endl;
	_fixed_point_val = to_assign._fixed_point_val;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destrucor called from Fixed." << std::endl;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits called from Fixed." << std::endl;
	return _fixed_point_val;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits called from Fixed." << std::endl;
	_fixed_point_val = raw;
}
