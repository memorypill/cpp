#include <iostream>

#define FLAG_1

#define CONDITION_1 1 

#ifdef FLAG_2
void fun1()
{
    std::cout << 1 << std::endl;
}
#elif CONDITION_1 > 0
void fun1()
{
    std::cout << 2 << std::endl;
}
#else
void fun1()
{
    std::cout << 3 << std::endl;
}
#endif

#define ADD(a, b) a + b

#define BAD_MULTILINE_MACROS(a, b) std::cout << a << std::endl; \
        std::cout << b << std::endl

// do { ... } while (0) pattern
#define GOOD_MULTILINE_MACROS(a, b) \
    do { \
        std::cout << a << std::endl; \
        std::cout << b << std::endl; \
    } while (0)

void conditional_compilation_example()
{
    std::cout << "conditional_compilation_example" << std::endl;
    fun1();
}

void macros_example()
{
    std::cout << "macros_example" << std::endl;

    if (ADD(2, 2) == 5)
        BAD_MULTILINE_MACROS(1, 2); // problem: second line is executed in any case!

    if (ADD(2, 2) == 5)
        GOOD_MULTILINE_MACROS(1, 2);

    if (ADD(2, 2) == 4)
        GOOD_MULTILINE_MACROS(1, 2);
}