#include <iostream>
#include <string>

// User-defined literal for converting feet to meters
constexpr double operator "" _ft(long double feet)
{
    // 1 foot is approximately 0.3048 meters
    return static_cast<double>(feet) * 0.3048;
}

class Unit
{
    int m_value;

public:

    int get_value() const { return m_value; }

    Unit(int arg) :
        m_value{ arg }
    {
    }

    // as method
    Unit operator+(int value)
    {
        return Unit(m_value + value);
    }

    int operator! () const
    {
        return -m_value;
    }

    int& operator[] (const int index)
    {
        m_value = index;
        return m_value;
    }

    int operator() (int value) { return m_value + value; }

    explicit operator std::string() { return std::to_string(m_value); }

    // as friend
    friend Unit operator-(const Unit& d1, const Unit& d2);
};

Unit operator+(const Unit& u1, const Unit& u2)
{
    return Unit(u1.get_value() + u2.get_value());
}

// as friend
Unit operator-(const Unit& u1, const Unit& u2)
{
    return Unit(u1.m_value + u2.m_value);
}

void custom_operators_example()
{
    std::cout << "custom_operators_example" << std::endl;

    auto value = 1.0_ft;
    std::cout << value << std::endl;

    Unit unit1 = 1;
    auto result = !unit1;
    std::cout << result << std::endl;

    unit1[0] = 1;
    std::cout << unit1[42] << std::endl; // 42

    std::string string_value = static_cast<std::string>(unit1);

    std::cout << string_value << std::endl; // 42
}