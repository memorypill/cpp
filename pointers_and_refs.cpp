#include <iostream>

int function(int arg)
{
    return arg;
}

int (*function_returning_function_pointer())(int)
{
    return function;
}

int function_takes_function_pointer(int(*function_pointer_arg)(int))
{
    return function_pointer_arg(1);
}

void poiners_example()
{
    std::cout << "poiners_example" << std::endl;

    int result1 = function_takes_function_pointer(function);
    std::cout << result1 << std::endl;

    int (*function_pointer)(int) = function_returning_function_pointer();

    int result2 = function_pointer(2);
    std::cout << result2 << std::endl;

    int a = 1;
    int* pa = &a; // pointer to a

    int a_value = *pa;
    long long address = (long long)pa; // address as integer value

    std::cout << address << std::endl;

    //  *const
    const int* ip1 = &a;
    const int *const ip2 = &a;

    int b = 2;

    ip1 = &b;
    //ip2 = &b; <- compilation error
}

// refs

void change_ref(int& arg_ref)
{
    arg_ref = 2;
}

// r-value ref
void r_value_ref(int&& r_value_ref)
{
    std::cout << r_value_ref << std::endl;
}

void refs_example()
{
    std::cout << "refs_example" << std::endl;

    int a = 1;
    int& a_ref = a;
    change_ref(a);
    // change_ref(1); // <- compilation error (r-value ref)
    std::cout << a_ref << std::endl; // 2
    
    r_value_ref(1); // ok
    // r_value_ref(a); // <- compilation error (l-value ref)
}