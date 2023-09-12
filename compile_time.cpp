#include <iostream>

// constexpr - C++11
// constinit - C++20
// consteval - C++20

constexpr int Version = 1;
constinit int NeedUpgadeVersion = Version + 1;

consteval int compute_fibonacci(const int n) {

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return compute_fibonacci(n - 1) + compute_fibonacci(n - 2);
}

constexpr int FibonacciOf7 = compute_fibonacci(7);

void compile_time_example()
{
    std::cout << "compile_time_example" << std::endl;

    static_assert(Version > 0);
    // static_assert(Version == 0); // <- compilation error
    
    // Version = 2; // -> compilation error
    NeedUpgadeVersion = Version + 2; // ok

    std::cout << FibonacciOf7 << std::endl;
}