#include "Dog.hpp"
#include "Cat.hpp"

#define ANIMAL_COUNT 6 // must be greater than zero

int	main () {
	Animal *animals[ ANIMAL_COUNT ];

	for ( int i = 0; i < ANIMAL_COUNT; i++ ) {
		if ( i < ( ANIMAL_COUNT / 2 ) ) {
			animals[i] = new Dog;
		}
		else {
			animals[i] = new Cat;
		}
	}

	std::cout << "All animals are created at main" << std::endl;
	std::cout << "--------------------" << std::endl;
	
	std::cout << animals[0]->get_idea(87) << std::endl;
	std::cout << animals[3]->get_idea(7) << std::endl;
	
	std::cout << "--------------------" << std::endl;
	
	for ( int i = 0; i < ANIMAL_COUNT; i++ ) {
		delete animals[i];
	}

	return 0;
}

// void __attribute__((destructor)) a() {
// 	system("leaks Brain");
// }
