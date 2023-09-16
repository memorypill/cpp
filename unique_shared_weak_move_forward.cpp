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