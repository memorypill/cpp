#include <iostream>

// Inheritance

class BaseCalass
{
private:
	virtual void base_private_method() {}
protected:
	virtual void base_protected_method() {}
public:
	virtual void base_public_method() {}
};

/* public-inheritance */
class PublicInheritedClass : public BaseCalass // (protected -> protected, public -> public)
{
	void test() // private by default
	{
		//this->private_method(); // not accessible!
		this->base_protected_method(); // protected - can be accessed by derived classes
		this->base_public_method(); // public
	}
};

/* protected-inheritance - by default */
class ProtectedInheritedClass : protected BaseCalass // (protected -> protected, public -> protected)
{
	void test()
	{
		//this->private_method(); // not accessible!
		this->base_protected_method(); // protected - can be accessed by derived classes
		this->base_public_method(); // protected - can be accessed by derived classes
	}
};

/* private-inheritance */
class PrivateInheritedClass : private BaseCalass // (protected -> private, public -> private)
{
	void test()
	{
		//this->private_method(); // not accessible!
		this->base_protected_method(); // private
		this->base_public_method(); // private
	}
};

class ProtectedInheritedSubClass : protected ProtectedInheritedClass
{
	void test()
	{
		//this->private_method(); // not accessible!
		this->base_protected_method(); // protected
		this->base_public_method(); // protected
	}
};

class PrivateInheritedSubClass : protected PrivateInheritedClass
{
	void test()
	{
		//this->private_method(); // not accessible!
		//this->base_protected_method(); // not accessible (as private member of PrivateInheritedClass)!
		//this->base_public_method(); // not accessible (as private member of PrivateInheritedClass)!
	}
};

void learn_inheritance()
{
	PublicInheritedClass public_inherited;

	public_inherited.base_public_method();
	//public_inherited.base_protected_method(); // not accessible!
	//public_inherited.base_private_method(); // not accessible!

	ProtectedInheritedClass protected_inherited;

	//protected_inherited.base_public_method(); // not accessible (as protected)!
	//public_inherited.base_protected_method(); // not accessible (as protected)!
	//public_inherited.base_private_method(); // not accessible!
}

// virtual

class AbstractClass
{
public:
	virtual void method1()
	{
		std::cout << "AbstractClass" << std::endl;
	}
	virtual void method2() = 0;
	virtual void method3() = 0;
};

class Class1 : public AbstractClass
{
private:
	virtual void method1() override
	{
		std::cout << "Class1" << std::endl;
	}

	virtual void method2() override
	{
		std::cout << "Class1" << std::endl;
	}

	virtual void method3() override
	{
		std::cout << "Class1" << std::endl;
	}
};

class SubClass1 : public Class1
{
private:
	virtual void method1() override
	{
		std::cout << "SubClass1" << std::endl;
	}
};

void learn_virtual()
{
	SubClass1 class1;

	AbstractClass* abstractClass = &class1;

	abstractClass->method1();
}

// Friendly: class, method, function

class MyClass1;

class ClassWithFriendlyMethod
{
public:
	void friendly_method(MyClass1& myclass1);
};

class MyClass1
{
private:
	void private_method() { }

	// friends
	friend void friend_function(MyClass1& obj);
	friend class MyFriend;
	friend void ClassWithFriendlyMethod::friendly_method(MyClass1& myclass1);
};

void ClassWithFriendlyMethod::friendly_method(MyClass1& myclass1)
{
	myclass1.private_method();
}

class MyFriend
{
	void test()
	{
		MyClass1 myClass1;
		myClass1.private_method(); // ok!
	}
};

void friend_function(MyClass1& obj)
{
	obj.private_method(); // ok!
}