#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	private:
		std::string _type;

	public:
		WrongAnimal();
		WrongAnimal( std::string );
		WrongAnimal( const WrongAnimal & );
		virtual	~WrongAnimal();
		WrongAnimal &operator=( const WrongAnimal & );

		void			makeSound() const;
		std::string		getType() const;
};

#endif
