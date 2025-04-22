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
	int i = 0;
	if (pList)
	{
		SAFE_DELETE(pList->pElement);
		//free(pList->pElement);
		SAFE_DELETE(pList);
		//free(pList);
	}
}

bool isArrayListFull(ArrayList* pList)
{
	int ret = false;

	if (pList)
	{
		if (pList->currentElementCount == pList->maxElementCount)
		{
			ret = true;
		}
	}

	return ret;
}

bool addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	bool ret = false;
	int i = 0;

	if (pList)
	{
		if (!isArrayListFull(pList))
		{
			if (position >= 0 && position <= pList->currentElementCount)
			{
				for (i = pList->currentElementCount - 1; i >= position; i--)
				{
					pList->pElement[i + 1] = pList->pElement[i];
				}
				pList->pElement[position] = element;
				pList->currentElementCount++;
				ret = true;
			}
			else
			{
				std::cout << "error, out of index\n";
			}
		}
		else
		{
			std::cout << "error, list is full\n";
		}
	}

	return ret;
}

bool removeALElement(ArrayList* pList, int position)
{
	bool ret = false;
	int i = 0;

	if (pList)
	{
		if (position >= 0 && position < pList->currentElementCount)
		{
			for (i = position; i < pList->currentElementCount - 1; i++)
			{
				pList->pElement[i] = pList->pElement[i + 1];
			}
			pList->currentElementCount--;
			ret = true;
		}
		else
		{
			std::cout << "error, out of index\n";
		}
	}

	return ret;
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	ArrayListNode* pReturn = nullptr;
	if (pList)
	{
		if (position >= 0 && position < getArrayListLength(pList))
		{
			pReturn = &(pList->pElement[position]);
		}
		else
		{
			std::cout << "error, out of index\n";
		}
	}

	return pReturn;
}

void displayArrayList(ArrayList* pList)
{
	int i = 0;
	if (pList)
	{
		std::cout << "max count : " << pList->maxElementCount << std::endl;
		std::cout << "current element count : " << pList->currentElementCount << std::endl;
		for (i; i < pList->currentElementCount; i++)
		{
			std::cout << i << ', ' << getALElement(pList, i)->data << std::endl;
		}
	}
	else
	{
		std::cout << "ArrayList is empty";
	}
}

void clearArrayLIst(ArrayList* pList)
{
}

int getArrayListLength(ArrayList* pList)
{
	int ret = 0;
	if (pList)
	{
		ret = pList->currentElementCount;
	}

	return ret;
}

bool addALElementFirst(ArrayList* pList, int element)
{
	int position = 0;
	ArrayListNode newNode;
	newNode.data = element;
	return addALElement(pList, position, newNode);
}

bool addALElementLast(ArrayList* pList, int element)
{
	bool ret = false;
	int position = 0;
	if (pList)
	{
		ArrayListNode newNode;
		newNode.data = element;
		position = getArrayListLength(pList);
		ret = addALElement(pList, position, newNode);
	}
	return ret;
}
