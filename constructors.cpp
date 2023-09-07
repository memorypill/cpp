#include <iostream>

class ClassWithSimpleConstructor
{
public:
	int property1;

	ClassWithSimpleConstructor(int value)
	{
		property1 = value;
	}
};

// explisit
class ClassWithExplicitConstructor
{
public:
	int property1;

	explicit ClassWithExplicitConstructor(int value)
	{
		property1 = value;
	}
};

void explisit_constructor_example()
{
	ClassWithSimpleConstructor classWithSimpleConstructor1 (1);
	ClassWithSimpleConstructor classWithSimpleConstructor2 = 2; // ok
	ClassWithSimpleConstructor classWithSimpleConstructor3 { 3 }; // parameter list initialization

	ClassWithExplicitConstructor classWithExplicitConstructor1(1);
	//ClassWithExplicitConstructor classWithExplicitConstructor2 = 2; // compillation error!
	ClassWithExplicitConstructor classWithExplicitConstructor3{ 3 };
}

// Inheritance

class BaseClassWithConstructor
{
public:
	int property1;
	int property2;
	int property3;

	BaseClassWithConstructor(int arg) :
		property1(arg),
		property2(1),
		property3{2}
	{
	}
};

class DerivedClassWithConstructor : BaseClassWithConstructor
{
public:
	DerivedClassWithConstructor(int arg) :
		BaseClassWithConstructor(arg)
	{
	}
};

// Copy and move constructors

class ClassWithDeletedCopyConstructor
{
public:
	ClassWithDeletedCopyConstructor()
	{
	}

	ClassWithDeletedCopyConstructor(ClassWithDeletedCopyConstructor& copy) = delete;
	ClassWithDeletedCopyConstructor(ClassWithDeletedCopyConstructor&& move) = default;
};

class ClassWithDeletedMoveConstructor
{
public:
	ClassWithDeletedMoveConstructor()
	{
	}

	ClassWithDeletedMoveConstructor(ClassWithDeletedMoveConstructor& copy) = default;
	ClassWithDeletedMoveConstructor(ClassWithDeletedMoveConstructor&& move) = delete;
};

void deleted_copy_constructor_example()
{
	ClassWithDeletedCopyConstructor c1;
	//ClassWithDeletedCopyConstructor c2 { c1 };  // <- compilation error
	//ClassWithDeletedCopyConstructor c3(c1);  // <- compilation error

	ClassWithDeletedCopyConstructor c4 = std::move(ClassWithDeletedCopyConstructor{}); // <- ok
}

void deleted_move_constructor_example()
{
	ClassWithDeletedMoveConstructor c1;
	ClassWithDeletedMoveConstructor c2{ c1 };  // <- ok
	ClassWithDeletedMoveConstructor c3(c1);  // <- ok

	//ClassWithDeletedMoveConstructor c4 = std::move(ClassWithDeletedMoveConstructor{}); // <- compilation error
}