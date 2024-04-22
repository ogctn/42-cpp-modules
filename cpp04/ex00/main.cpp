#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main () {
	std::cout << "----1----" << std::endl;
	Animal a, b;
	
	std::cout << "----2----" << std::endl;
	b = a;
	a.makeSound();
	b.makeSound();
	
	std::cout << "----3----" << std::endl;
	Dog c;
	c.makeSound();

	std::cout << "----4----" << std::endl;
	Cat d;
	d.makeSound();

	std::cout << "----5----" << std::endl;
	Animal e;
	std::cout << "\n---> e: " + e.getType() + "\n" << std::endl;
	e = Animal(Cat(d));
	std::cout << "\n---> e: " + e.getType() + "\n" << std::endl;

	std::cout << "----6----" << std::endl;
	std::cout << "a: " + a.getType() << ", c: " + c.getType() << ", d: " + d.getType() << std::endl; 

	std::cout << "----DESTRR----" << std::endl;


	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound(); //will output the cat sound!
	// j->makeSound();
	// meta->makeSound();

	// delete meta;
	// delete j;
	// delete i;

	// -------------------------------------- //

	// const WrongAnimal* meta = new WrongAnimal();
	// const WrongAnimal* i = new WrongCat();
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound(); //will output the animal sound (WrongCat)
	// meta->makeSound();

	// delete meta;
	// delete i;

	return 0;
}

// void __attribute__((destructor)) a() {
// 	system("leaks Animal");
// }
