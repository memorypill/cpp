#include <iostream>
#include <functional>

void lambda_example()
{
    int a = 5;
    int b = 10;

    std::function<int(int, int)> sum1 = [](int x, int y) { return x + y; }; // no capture

    auto sum2 = [a, b]() { return a + b; }; // only a and b by value

    // mutable
    auto sum3 = [=]() mutable {  // all by value
        a = a + 1; // only inside lambda
        return a + b;
    };

    auto sum4 = [&]() { return a + b; }; // all by ref

    auto sum5 = [&, a]() { return a + b; }; // all by ref but a by value

    int result = sum2();

    std::cout << result << std::endl;
}
