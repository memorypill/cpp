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

class ClassWithDefaultConstructor
{
public:
	int Prop1 = 1;

	ClassWithDefaultConstructor()
	{

	}

	//ClassWithDefaultConstructor(ClassWithDefaultConstructor& copy) = delete;
	//ClassWithDefaultConstructor(ClassWithDefaultConstructor&& copy) = delete;
};

void default_coustructors_example()
{
	//ClassWithDefaultConstructor obj1;
//obj1.Prop1 = 37;

//ClassWithDefaultConstructor obj2(obj1);

	ClassWithDefaultConstructor obj3;
	ClassWithDefaultConstructor& obj3Ref = obj3;
	ClassWithDefaultConstructor obj4(obj3Ref);

	std::cout << obj3.Prop1 << std::endl; // 37 - copied
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

// copy and move

// Constructor

class ClassWithDeletedCopyAndMoveConstructors
{
public:
	ClassWithDeletedCopyAndMoveConstructors()
	{
	}

	ClassWithDeletedCopyAndMoveConstructors(ClassWithDeletedCopyAndMoveConstructors& copy) = delete;
	ClassWithDeletedCopyAndMoveConstructors(ClassWithDeletedCopyAndMoveConstructors&& move) = delete;
};

void default_constructors_example()
{
	//ClassWithDeletedCopyAndMoveConstructors c1;
	//ClassWithDeletedCopyAndMoveConstructors c2 { c1 };
	//ClassWithDeletedCopyAndMoveConstructors c3 = ClassWithDeletedCopyAndMoveConstructors{};

	ClassWithDeletedCopyAndMoveConstructors c3 = ClassWithDeletedCopyAndMoveConstructors{};

	//ClassWithDeletedCopyAndMoveConstructors c4 = c3; // Ошибка компиляции: конструктор копирования удален
	//ClassWithDeletedCopyAndMoveConstructors c5 = std::move(c3); // Ошибка компиляции: конструктор перемещения удален
}

