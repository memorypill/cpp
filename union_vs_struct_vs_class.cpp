#include <cstdint>
#include <iostream>

// ******************************** union ********************************

union Union1
{
    // have the same address!
    int16_t short1;
    int32_t long1;

    void test() { } // ok!
};

// size
union Union2
{
    uint16_t short1;
    uint32_t long1:1; // 1 bit size
};

void unions_example()
{
    std::cout << "union_example" << std::endl;

    Union1 union1;
    union1.long1 = 0;
    union1.short1 = -1;

    std::cout << union1.long1 << std::endl; // 65535

    Union2 union2;
    union2.long1 = 0;
    union2.short1 = 0b111;

    std::cout << union2.long1 << std::endl; // 1
}

// ******************************** struct ********************************

// fields size
struct FixedSizeStruct
{
    unsigned int a : 1; // 1 bit
    unsigned int b : 2; // 2 bits
};

// fields size
struct alignas(8) Aligned8FixedSizeStruct
{
    unsigned int a : 1; // 1 bit
    unsigned int b : 2; // 2 bits
};

struct BaseStruct
{
    // public by default (class - private by default!)
    void public_method()
    {
        std::cout << "ok" << std::endl;
    }
};

struct InheritedStruct : BaseStruct
{
    void test()
    {
        this->public_method();
    }
};

void structs_example()
{
    std::cout << "structs_example" << std::endl;

    FixedSizeStruct fixedSizeStruct;
    Aligned8FixedSizeStruct aligned8FixedSizeStruct;

    std::cout << "sizeof(fixedSizeStruct)=" << sizeof(fixedSizeStruct) << std::endl; // 4
    std::cout << "alignof(FixedSizeStruct)=" << alignof(FixedSizeStruct) << std::endl; // 4
    std::cout << "sizeof(aligned8FixedSizeStruct)=" << sizeof(aligned8FixedSizeStruct) << std::endl; // 8
    std::cout << "alignof(Aligned8FixedSizeStruct)=" << alignof(Aligned8FixedSizeStruct) << std::endl; // 8

    InheritedStruct struct1;
    struct1.test();
}

// ******************************** class ********************************

class BaseClass
{
    // private by default (struct - public by default!)
    void private_method()
    {
    }
};

class InheritedClass : BaseClass
{
    void test()
    {
        //this->public_method(); // <- compilation error
    }
};