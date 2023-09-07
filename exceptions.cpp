#include <iostream>

void exceptions_example()
{
	std::cout << "exceptions_example" << std::endl;

	try
	{
		//throw 1; // eny type

		throw "test";
	}
	catch (int error)
	{
		std::cout << "error no. " << error << std::endl;

		throw; // re-throw
	}
	catch (...)
	{
		std::cout << "unknown error" << std::endl;
	}
}