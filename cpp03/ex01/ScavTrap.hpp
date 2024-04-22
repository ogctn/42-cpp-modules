#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap {
	private:
		bool	_gate;

	public:
		ScavTrap();
		ScavTrap( std::string );
		ScavTrap( const ScavTrap & );
		~ScavTrap();
		ScavTrap &operator=( const ScavTrap & );

		void	guardGate();
		void	attack( const std::string & );
};

#endif
