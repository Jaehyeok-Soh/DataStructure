#include "pch.h"
void mergeSort(int value[], int buffer[], int start, int end)
{
	int middle(0);

	if (start < end)
	{
		middle = (start + end) / 2;
		mergeSort(value, buffer, start, middle);
		mergeSort(value, buffer, middle + 1, end);

		mergeSortInternal(value, buffer, start, middle, end);
	}
}

void mergeSortInternal(int value[], int buffer[], int start, int middle, int end)
{
	int i(start);// 1st partition
	int j(middle + 1);// 2nd partition
	int k(start);//current buffer index

	while (i <= middle && j <= end)
	{
		if (value[i] <= value[j])
		{
			buffer[k] = value[i];
			i++;
		}
		else
		{
			buffer[k] = value[j];
			j++;
		}
		k++;
	}

	if (i > middle)
	{
		for (auto t = j; t <= end; t++, k++)
		{
			buffer[k] = value[t];
		}
	}
	else
	{
		for (auto t = i; t <= middle; t++, k++)
		{
			buffer[k] = value[t];
		}
	}

	for (auto t = start; t <= end; t++)
	{
		value[t] = buffer[t];
	}
}
