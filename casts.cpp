#include <iostream>

class Base { virtual void foo() {} };
class Derived : public Base {};

void casts_example()
{
	std::cout << "casts_example" << std::endl;

	// static_cast
	float f = 3.14f;
	int i = static_cast<int>(f);

	// dynamic_cast
	Base* basePtr = new Derived;
	Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

	if (derivedPtr)
		std::cout << "dynamic_cast ok" << std::endl;
	else
		std::cout << "wrong dynamic_cast" << std::endl;

	// const_cast
	const int x = 1;
	int y = const_cast<int&>(x);
	y = 2;

	std::cout << y << std::endl;

	// reinterpret_cast (re interpretation)
	long long int address = reinterpret_cast<long long int>(basePtr);
	std::cout << "address=" << address << std::endl;

	// C-style cast
	float pi = 3.14f;
	int int_pi = (int)f;

	std::cout << int_pi << std::endl;

	delete basePtr;
}