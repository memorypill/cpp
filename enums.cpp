#include <iostream>

enum Color
{
	Red,
	Green,
	Blue
};

void print_color(Color color)
{
	switch (color)
	{
	case Red:
		std::cout << "RED" << std::endl;
		break;
	case Green:
		std::cout << "GREEN" << std::endl;
		break;
	default:
		std::cout << "Other" << std::endl;
		break;
	}
}

void enum_example()
{
	std::cout << "enum_example" << std::endl;

	print_color(Color::Red);
}