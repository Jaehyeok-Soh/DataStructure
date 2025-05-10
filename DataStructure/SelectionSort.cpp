#include "pch.h"

void selectionSort(int value[], int count)
{
	int min(0), temp(0);

	for (auto i = 0; i < count; i++)
	{
		min = value[i];
		for (auto j = 0; j < count; j++)
		{
			if (value[j] < value[min])
			{
				min = j;
			}
		}

		temp = value[i];
		value[i] = value[min];
		value[min] = temp;
	}
}

void selectionExample()
{
	int values[] = { 80, 50, 70, 10, 60, 20, 40, 30 };

	std::cout << "before sort\n";
	printArray(values, 8);

	selectionSort(values, 8);

	std::cout << "aftger sort\n";
	printArray(values, 8);
}

void printArray(int value[], int count)
{
	for (auto i = 0; i < count; i++)
	{
		std::cout << value[i] << '\t';
	}
	std::cout << '\n';
}