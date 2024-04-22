#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
	private:
		Brain	*_brain;

    public:
        Cat( void );
		Cat( const Cat & );
		~Cat( void );
		Cat &operator=( const Cat & );

		void		makeSound( void ) const;
		std::string	get_idea( unsigned int ) const;
};

#endif
