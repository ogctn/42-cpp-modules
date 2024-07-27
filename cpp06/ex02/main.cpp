#include "foo.hpp"

int main() {
	srand(24 + time(NULL));
	
	{
		Base *d = generate();
		std::cout << "Random class: " << std::endl;
		identify(d);
		std::cout << "----------" << std::endl;
		delete d;
	}

	{
		Base	*d_B = new B(); 
		Base	d0_C = C();		// object slicing
		Base	*d0_C1 = new C();
		Base	&d0_Cc = *(d0_C1);
		C 		d_C = C();

		identify(d_B);
		identify(d0_C);
		identify(d0_C1);
		identify(d0_Cc);
		identify(d_C);

		delete d_B;
		delete d0_C1;
	}
	return (0);
}
