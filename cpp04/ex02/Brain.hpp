#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>


class Brain {
	protected:
		std::string _ideas[100];
	
	public:
		Brain( void );
		~Brain( void );
		Brain( const Brain & );
		Brain	&operator=( const Brain & );

		void		set_idea( unsigned int, std::string );
		std::string	get_idea( unsigned int ) const;
};

#endif
