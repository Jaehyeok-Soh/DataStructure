#include "pch.h"

void insertionSort(int value[], int count)
{
	int j(0), temp(0);

	for (auto i = 1; i < count; i++)
	{
		temp = value[i];
		j = i;
		while ((j > 0) && value[j - i] > temp)
		{
			value[j] = value[j - 1];
			j = j - 1;
		}
		value[j] = temp;
	}
}