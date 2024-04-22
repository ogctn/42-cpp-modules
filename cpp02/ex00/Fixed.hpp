#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int					_fixed_point_val;
		static const int	_fraction_bits = 8;

	public:
		Fixed();
		Fixed( const Fixed & );
		Fixed &operator=( const Fixed & );
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const );
};


#endif
