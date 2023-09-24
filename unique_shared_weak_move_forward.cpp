#include <iostream>

void function_get_ref(int& i)
{
    std::cout << "ref" << std::endl;
}

void function_get_ref(int&& i)
{
    std::cout << "r-value ref" << std::endl;
}

template<typename T>
void wrapper_with_forward(T&& arg) // T&& - forwarding reference or universal reference
{
    function_get_ref(std::forward<T>(arg));
}

template<typename T>
void wrapper(T&& arg) // T&& - forwarding reference or universal reference
{
    function_get_ref(arg);
}

void forward_example()
{
    int i = 1;
    wrapper_with_forward(i); // ref
    wrapper_with_forward(2); // r-value ref

    wrapper(i); // ref
    wrapper(2); // ref
}

// Smart pointers

class TestClassForPtr {
public:
    TestClassForPtr()
    {
        std::cout << "-constructor-" << std::endl;
    }

    TestClassForPtr(const TestClassForPtr& copy)
    {
        std::cout << "-copy constructor-" << std::endl;
    }

    TestClassForPtr(const TestClassForPtr&& move) noexcept
    {
        std::cout << "-move constructor-" << std::endl;
    }

    ~TestClassForPtr()
    {
        std::cout << "-destructor-" << std::endl;
    }

    void fun1()
    {
        std::cout << "-fun1-" << std::endl;
    }
};

void unique_ptr_example()
{
    std::unique_ptr<TestClassForPtr> unique_ptr1 = std::make_unique<TestClassForPtr>();
    unique_ptr1->fun1();

    TestClassForPtr testClassForPtr = TestClassForPtr();
    testClassForPtr.fun1();

    std::unique_ptr<TestClassForPtr> unique_ptr2 = std::make_unique<TestClassForPtr>(std::move(testClassForPtr));
    unique_ptr2->fun1();
    // testClassForPtr->fun1(); // error - not accessible after std::move
}

void fun_with_shared_ptr_arg(std::shared_ptr<TestClassForPtr> arg)
{
    std::cout << "use_count=" << arg.use_count() << std::endl;
    arg->fun1();
}

void shared_ptr_example()
{
    std::cout << "shared_ptr_example" << std::endl;
    std::shared_ptr<TestClassForPtr> shared_ptr1 = std::make_shared<TestClassForPtr>();
    shared_ptr1->fun1();

    std::shared_ptr<TestClassForPtr> shared_ptr2 = std::make_shared<TestClassForPtr>(*shared_ptr1); // copy constructor
    shared_ptr2->fun1();

    fun_with_shared_ptr_arg(shared_ptr1);
}

std::weak_ptr<TestClassForPtr> weak_ptr1;

void fun_weak_ptr()
{
    std::shared_ptr<TestClassForPtr> shared_ptr1 = weak_ptr1.lock();

    if (shared_ptr1)
        shared_ptr1->fun1();
}

void weak_ptr_example()
{
    std::cout << "weak_ptr_example" << std::endl;

    std::shared_ptr<TestClassForPtr> shared_ptr1 = std::make_shared<TestClassForPtr>();
    weak_ptr1 = shared_ptr1;
    fun_weak_ptr();
    std::cout << "weak_ptr1.use_count=" << weak_ptr1.use_count () << std::endl;
}

void smart_ptr_example()
{
    std::cout << "smart_ptr_example" << std::endl;
    unique_ptr_example();
    shared_ptr_example();
    weak_ptr_example();
}