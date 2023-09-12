#include <iostream>

void fundamental_operators_example()
{
    // arithmetic
    std::cout << 2 + 2 << std::endl; // 4
    std::cout << 4 - 2 << std::endl; // 2
    std::cout << 2 * 2 << std::endl; // 4
    std::cout << 4 / 2 << std::endl; // 2

    std::cout << 10 % 4 << std::endl; // 2 (remainder of division)

    int i = 0;
    
    // increment
    std::cout << ++i << std::endl; // 1 - pre
    std::cout << i++ << std::endl; // 1 - post
    std::cout << i << std::endl; // 2

    // decrement
    std::cout << --i << std::endl; // 1 - pre
    std::cout << i-- << std::endl; // 1 - post
    std::cout << i << std::endl; // 0

    // bitwise
    std::cout << (1 | 2) << std::endl; // 3 [OR]
    std::cout << (1 & 1) << std::endl; // 1 [AND]
    std::cout << (1 ^ 1) << std::endl; // 0 [XOR]
    std::cout << (~ (char)0b11110000) << std::endl; // [NOT] 0b11110000->0b00001111

    std::cout << (1 << 2) << std::endl; // 4 (left shift)
    std::cout << (4 >> 2) << std::endl; // 1 (right shift)

    // logical
    int a = 1;
    int b = 2;

    std::cout << (a == 1) << std::endl; // 1 (true)
    std::cout << (a != 1) << std::endl; // 0 (false)

    std::cout << ((a == 1) && (b == 1)) << std::endl; // AND 0 (false)
    std::cout << ((a == 1) || (b == 1)) << std::endl; // OR 1 (true)
    std::cout << (!(a == 1)) << std::endl; // NOT 0 (false)

    // ternary
    std::cout << ((a > b) ? a : b) << std::endl; // 2 (true -> a, false -> b)

    // three-way comparison <=>
    std::strong_ordering res = a <=> b; // res < 0

    if (res < 0)
        std::cout << "a is less than b" << std::endl; // <- this
    else if (res > 0)
        std::cout << "a is greater than b" << std::endl;
    else if (res == 0)
        std::cout << "a and b are equal" << std::endl;
    else
        std::cout << "a and b are unordered" << std::endl;
}

void precedence_example()
{
    // TODO: https://en.cppreference.com/w/cpp/language/operator_precedence
    std::cout << 2 + 2 * 2 << std::endl; // 6
    std::cout << (2 + 2) * 2 << std::endl; // 8
}