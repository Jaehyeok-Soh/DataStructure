#include "pch.h"

#include "ArrayList.h"

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList* pReturn = nullptr;
	int i = 0;

	if (maxElementCount > 0)
	{
		pReturn = new ArrayList;
		//pReturn = (ArrayList*)malloc(sizeof(ArrayList));

		if (pReturn)
		{
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = nullptr;
		}
		else
		{
			std::cout << "error, please allocate memory. createArrayList()\n";
			return nullptr;
		}
	}
	else
	{
		std::cout << "error, max element count\n";
		return nullptr;
	}

	pReturn->pElement = new ArrayListNode[maxElementCount];
	//pReturn->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * maxElementCount);

	if (!pReturn->pElement)
	{
		std::cout << "error, please allocate memory. createArrayList() _2\n";
		
		SAFE_DELETE(pReturn);
		//free(pReturn);pReturn=nullptr
	}

	memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount);

	return pReturn;
}

void deleteArrayList(ArrayList* pList)
{
}

bool isArrayListPull(ArrayList* pList)
{
	return false;
}

bool addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	return false;
}

bool removeALElement(ArrayList* pList, int position)
{
	return false;
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	return nullptr;
}

void displayArrayList(ArrayList* pList)
{
}

void clearArrayLIst(ArrayList* pList)
{
}

int getArrayListLength(ArrayList* pList)
{
	return 0;
}
