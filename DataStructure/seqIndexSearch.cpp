#include "pch.h"

//struct IndexTable
//{
//	int position;
//	int key;
//};

int sequentialIndexSearch(int value[], int size, IndexTable index[], int indexSize, int key)
{
	int ret = -1;
	int i(0), start(0), end(0);

	if (key >= value[0] && key <= value[size-1])
	{
		for (i = 0; i < indexSize; i++)
		{
			if (index[i].key > key)
			{
				break;
			}
		}

		if (i >= indexSize)
		{
			start = index[i - 1].position;
			end = size - 1;
		}
		else
		{
			start = index[i - 1].position;
			end = index[i].position - 1;
		}

		ret = sequentialRangeSearchAsendingSorted(value, start, end, key);
	}

	return ret;
}

int sequentialRangeSearchAsendingSorted(int value[],int start,int end,int key)
{
	int ret = -1;
	int i(0);
	for (i = start; i <= end && value[i] < key; i++)
	{
		//do nothing
	}

	if (i <= end && value[i] == key)
	{
		ret = i;
	}

	return ret;
}

IndexTable* createIndexTable(int value[], int size, int indexSize)
{
	IndexTable* pReturn = nullptr;
	int i(0), ratio(0);

	if (size <= 0 || indexSize <= 0)
	{
		std::cout << "error, please check size(indexSize)\n";
	}

	ratio = size / indexSize;
	if (size%indexSize>0)
	{
		ratio = ratio + 1;
	}

	pReturn = new IndexTable[indexSize]();
	for (auto i = 0; i < indexSize; i++)
	{
		pReturn[i].position = i * ratio;
		pReturn[i].key = value[i * ratio];
	}

	return pReturn;
}