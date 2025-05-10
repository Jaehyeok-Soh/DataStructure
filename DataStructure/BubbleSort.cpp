#include "pch.h"

void bubbleSort(int value[], int count)
{
	int temp(0);

	for (auto i = count; i >= 0; i--)
	{
		for (auto j = 0; j < i; j++)
		{
			if (value[j - 1] > value[j])
			{
				temp = value[j - 1];
				value[j - 1] = value[j];
				value[j] = temp;
			}
		}
	}
}