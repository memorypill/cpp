#include <iostream>
#include <vector>
#include <concepts>

// class vs typename

template<class T>
T templated_function1(T arg) { return arg + 1; }

template<typename T> // [typename] equivalent to [class]
T templated_function2(T arg) { return arg + 1; }

template <typename int value> // only typename is accepted!!!
int templated_function3_example()
{
    return value;
}

// templated value
template <class T>
typename T templated_value;

// non-type parameter or value parameter
template <int int_value>
int get_parameter()
{
    return int_value;
}

// default template type
template <class T = char>
void print_with_default(T value)
{
    std::cout << value << std::endl;
}

// template specialization
template <class T>
void print_value(T value)
{
    std::cout << value << std::endl;
}

template <>
void print_value<double>(double value)
{
    std::cout << "double: " << std::scientific << value << std::endl;
}

// templated class
template<class T>
class TemplatedClass
{
public:
    T value;
};

// T is templated class
template<template<class> class T>
class ClassWithTAsTemplatedClass
{
public:
    T<int> value;
};

// Parameter pack or variadic templates
template<class... TArgs>
auto sum(TArgs... args)
{
    return (args + ...); // fold-expressions C++17
}

// auto + decltype
template<class T>
auto add(const T& a, const T& b) -> decltype(a + b)
{
    return a + b;
}

// requires
template <class T>
    requires std::is_same<T, int>::value
T sum_of_int(T a, T b)
{
    return a + b;
}

// concept https://devdocs.io/cpp/header/concepts
template <class T>
concept sizeof_4_concept = sizeof(T) == 4;


template <sizeof_4_concept T>
void print_value_with_sizeof_4(T value)
{
    std::cout << value << std::endl;
}

// concept + requires
template <class T>
concept unsigned_concept = requires(T t)
{
    { t + 0 } -> std::unsigned_integral;
};

void function_with_concept(unsigned_concept auto u)
{
}

void templates_example()
{
    std::cout << "templates_example" << std::endl;

    int result1 = templated_function1<int>(1);
    int result2 = templated_function2<int>(1);

    std::cout << "result1=" << result1 << " result2=" << result2 << std::endl;

    int result3 = get_parameter<1>();

    std::cout << "result3=" << result3 << std::endl;

    print_with_default('w'); // char
    print_with_default(42); // UB

    // template specialization
    print_value(1);
    print_value(1.123);

    // templated calss with templated class T
    ClassWithTAsTemplatedClass<TemplatedClass> classWithTAsTemplatedClass;
    classWithTAsTemplatedClass.value.value = 1;

    // variadic templates
    int total = sum(1, 2, 3, 4, 5, 6, 7);
    std::cout << total << std::endl;

    int result4 = add(2, 2);
    std::cout << "result4=" << result4 << std::endl;

    // requires
    int result5 = sum_of_int(1, 1);
    // result5 = sum_of_int(1, 1.1); // error
    std::cout << "result5=" << result5 << std::endl;

    // concept
    int i = 1;
    //print_value_with_sizeof_4_v2(3);
    //print_value_with_sizeof_4(1.0f); // error

    std::vector<int> intVector = { 1, 2, 3, 4, 5 };
    
    function_with_concept(1U);
    //function_with_concept(1); // error
}