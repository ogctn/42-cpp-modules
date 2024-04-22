#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
	protected:
		std::string	_name;
		int			_hp;
		int			_energy;
		int			_ad;

	public:
		ClapTrap();
		ClapTrap( std::string );
		ClapTrap( const ClapTrap & );
		virtual ~ClapTrap();
		ClapTrap &operator=( const ClapTrap & );

		void	attack( const std::string & );
		void	takeDamage( unsigned int );
		void	beRepaired( unsigned int );

};

#endif
