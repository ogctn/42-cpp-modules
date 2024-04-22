#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria {
	protected:
		std::string	_type;

	public:
		AMateria( void );
		AMateria( std::string const & type );
		AMateria( const AMateria & );
		virtual ~AMateria( void );

		AMateria &operator=( const AMateria & );

		virtual AMateria* clone( void ) const = 0;
		std::string const & getType( void ) const;
		virtual void use( ICharacter& target );
};

#endif
