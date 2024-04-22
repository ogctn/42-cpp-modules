#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int					_fixed_point_val;
		static const int	_fraction_bits = 8;

	public:
		Fixed();
		Fixed( const int );
		Fixed( const float );
		Fixed( const Fixed & );
		~Fixed();

		Fixed	&operator=( const Fixed & );
		bool	operator>( const Fixed & ) const;
		bool	operator<( const Fixed & ) const;
		bool	operator>=( const Fixed & ) const;
		bool	operator<=( const Fixed & ) const;
		bool	operator==( const Fixed & ) const;
		bool	operator!=( const Fixed & ) const;
	
		Fixed	operator+( const Fixed & ) const;
		Fixed	operator-( const Fixed & ) const;
		Fixed	operator*( const Fixed & ) const;
		Fixed	operator/( const Fixed & ) const;

		Fixed	operator++();
		Fixed	operator--();
		Fixed	operator++( int );
		Fixed	operator--( int );

		static Fixed &min( Fixed &, Fixed & );
		static  Fixed &max( Fixed &, Fixed & );
		static const Fixed &min( const Fixed &, const Fixed & );
		static const Fixed &max( const Fixed &, const Fixed & );

		int		getRawBits( void ) const;
		void	setRawBits( int const );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator<<( std::ostream &os, const Fixed & );

#endif
