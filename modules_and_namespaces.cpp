#include <iostream>

import my_module1;

namespace namespace1
{

	void function_from_namespace()
	{
		std::cout << "from namespace1" << std::endl;
	}
}

namespace namespace2
{
	void function_from_namespace()
	{
		std::cout << "from namespace2" << std::endl;
	}
}

using namespace namespace2;

void modules_and_namespaces()
{
	std::cout << "modules_and_namespaces" << std::endl;

	namespace1::function_from_namespace();
	namespace2::function_from_namespace();
	function_from_namespace(); // using namespace namespace2

	hello_from_module1();
}