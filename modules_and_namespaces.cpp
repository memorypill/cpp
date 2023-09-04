#include <iostream>

//import my_module1;

namespace namespace1
{

	void function()
	{
		std::cout << "from namespace1" << std::endl;
	}
}

namespace namespace2
{
	void function()
	{
		std::cout << "from namespace2" << std::endl;
	}
}

void modules_and_namespaces()
{
	std::cout << "modules_and_namespaces" << std::endl;

	namespace1::function();
	namespace2::function();

	//hello_from_module1();
}