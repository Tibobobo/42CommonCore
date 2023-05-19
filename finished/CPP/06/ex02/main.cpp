#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void) {

	Base *ptr = NULL;
	srand(time(NULL));
	int random = rand() % 3;
	if (random == 0)
		ptr = new A;
	else if (random == 1)
		ptr = new B;
	else
		ptr = new C;
	return (ptr);
}

void	identify(Base *p) {

	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "The real type of pointed object is A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "The real type of pointed object is B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "The real type of pointed object is C" << std::endl;
	else
		std::cout << "Okay now we have a problem..." << std::endl;
}

void	identify(Base &p) {

	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "The real type of pointed object is A" << std::endl;
		return ;
	}
	catch (std::exception &e) {
		;
	}
	try {
		B &b = dynamic_cast<B &>(p);
		std::cout << "The real type of pointed object is B" << std::endl;
		return ;
	}
	catch (std::exception &e) {
		;
	}
	try {
		C &c = dynamic_cast<C &>(p);
		std::cout << "The real type of pointed object is C" << std::endl;
		return ;
	}
	catch (std::exception &e) {
		;
	}
	std::cout << "Okay now we have a problem..." << std::endl;
}

int	main(void) {

	Base *ptr = generate();
	std::cout << "A,B or C object randomly generated and pointed to by Base (parent class) pointer" << std::endl;

	identify(ptr);
	
	Base &ref = *ptr;

	identify(ref);

	delete ptr;
	return (0);
}