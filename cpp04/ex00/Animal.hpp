#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	private:
		std::string _type;

	public:
		Animal();
		Animal( std::string );
		Animal( const Animal & );
		virtual	~Animal();
		Animal &operator=( const Animal & );

		virtual void	makeSound() const;
		std::string		getType() const;
};

#endif
