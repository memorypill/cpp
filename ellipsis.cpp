#include <iostream>
#include <cstdarg>

void ellipsis_example(int count, ...)
{
	std::cout << "ellipsis_example" << std::endl;

	va_list list;
	va_start(list, count);

	for (int i = 0; i < count; i++)
	{
		int number = va_arg(list, int);
		std::cout << number << std::endl;
	}

	va_end(list);
}