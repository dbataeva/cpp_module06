#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	srand(static_cast<unsigned int>(time(0)));
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
	int i = static_cast<int>(rand() * fraction * 3);
	switch (i)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
	}
	return (new C);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	return ;
}

void identify(Base& p) {
	A a;
	B b;
	C c;
	try {
		a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return ;
	(void)a;
	(void)b;
	(void)c;
}

int main (void) {
	std::cout << "=== generate some object (A or B or C - random) ===" << std::endl;
	Base *a = generate();
	std::cout << "\n=== try identify object (A or B or C) with pointer ===" << std::endl;
	identify(a);
	std::cout << "\n===try identify object (A or B or C) with reference ===" << std::endl;
	identify(*a);

	delete a;
	return (0);
}