#include <iostream>

void cycles_example()
{
	int j = 10;

	// pre
	while (true)
	{
		if (j <= 0)
			break;

		j--;

		if (j == 5)
			continue;
	}

	j = 10;

	// post
	do
	{
		switch (j)
		{
		case 1:
			break;
		case 2:
			break;
		default:
			break;
		}

		j--;

	} while (j > 0);

	// for
	for (int i = 0; i < 10; i++)
	{
	}

	// foreach
	int array1[10];

	for (int element : array1)
	{
		std::cout << element << std::endl;
	}

	// goto (not recommended)

	j = 10;

label:

	j--;

	if (j > 0)
		goto label;
}