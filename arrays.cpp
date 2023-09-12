#include <iostream>

// array by reference
void print_array(const int(&simple_array)[3])
{
    for (int i : simple_array)
    {
        std::cout << i << std::endl;
    }
}

void arrays_example()
{
    std::cout << "arrays_example" << std::endl;

    int simple_array[]{ 0, 2, 3 }; // stack

    simple_array[0] = 1;

    print_array(simple_array);

    // pointer to array
    int* arr_pointer = simple_array;

    arr_pointer++; // skip arr[0]

    *arr_pointer = 20; // arr[1] = 20;

    print_array(simple_array);

    // dynamic array
    int* arr_pointer1 = new int[3];// <- allocate memory (heap)

    int* arr_pointer2 = arr_pointer1;

    *arr_pointer2++ = 0;
    *arr_pointer2++ = 1;
    *arr_pointer2++ = 2;

    // standard way
    arr_pointer1[0] = -1;

    int* arr_pointer3 = arr_pointer1;

    std::cout << "dynamic array" << std::endl;

    std::cout << (*arr_pointer3++) << std::endl; // 0
    std::cout << (*arr_pointer3++) << std::endl; // 1
    std::cout << (*arr_pointer3++) << std::endl; // 2

    delete[] arr_pointer1; // <- deallocate memory

    // multi-dimensional
    int arr2x3[2][3] =
    {
       { 1, 2, 3 },
       { 4, 5, 6 }
    };

    arr2x3[0][0] = 10;
    arr2x3[0][1] = 20;
    arr2x3[0][2] = 30;

    arr2x3[1][0] = 40;
    arr2x3[1][1] = 50;
    arr2x3[1][2] = 60;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << arr2x3[i][j] << " ";
        }

        std::cout << std::endl;
    }
}