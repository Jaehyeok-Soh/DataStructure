#include "pch.h"

void shellSort(int value[], int count)
{
	int interval(count/2);

	while (interval >= 1)
	{
		for (auto i = 0; i < interval; i++)
		{
			shellInsertionSort(value, i, count - 1, interval);
		}

		interval = interval / 2;
	}
}

void shellInsertionSort(int value[], int start, int end, int interval)
{
	int item(0), index(0);
	for (auto i = start + interval; i <= end; i = i + interval)
	{
		item = value[i];
		index = i - interval;
		while ((index >= start) && item < value[index])
		{
			value[index + interval] = value[index];
			index = index - interval;
		}

		value[index + interval] = item;
	}
}