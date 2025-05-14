#include "pch.h"
#include "ArrayHeap.h"

HeapNode::HeapNode(int _key)
{
	key = _key;
}

ArrayHeap::ArrayHeap(int elementCount)
{
	maxElementCount = elementCount;
	pElement = new HeapNode[elementCount + 1];
}

ArrayHeap::~ArrayHeap()
{
}

void ArrayHeap::displayArrayHeap()
{
	for (int i = 1; i <= currentElementCount; i++)
	{
		std::cout << i << "-" << pElement[i].key << std::endl;
	}
}

ArrayMaxHeap::~ArrayMaxHeap()
{
	deleteArrayMaxHeap();
}

void ArrayMaxHeap::deleteArrayMaxHeap()
{
	if (pElement)
	{
		SAFE_DELETE(pElement);
	}
}

void ArrayMaxHeap::insertMaxHeapAH(HeapNode element)
{
	if (currentElementCount == maxElementCount)
	{
		std::cout << "heap full\n";
		return;
	}

	currentElementCount++;
	int i(currentElementCount);
	while ((i != 1) && (element.key > pElement[i/2].key))
	{
		pElement[i] = pElement[i / 2];
		i /= 2;
	}

	pElement[i] = element;
}

HeapNode* ArrayMaxHeap::deleteMaxHeapAH()
{
	HeapNode* pReturn = nullptr;
	HeapNode* pTemp = nullptr;

	int i(0), parent(0), child(0);

	if (currentElementCount > 0)
	{
		pReturn = new HeapNode();
		*pReturn = pElement[1];

		i = currentElementCount;
		pTemp = &pElement[i];
		currentElementCount--;

		parent = 1;
		child = 2;
		while (child <= currentElementCount)
		{
			if ((child < currentElementCount)
				&& (pElement[child].key < pElement[child + 1].key))
			{
				child++;
			}

			if (pTemp->key >= pElement[child].key)
			{
				break;
			}

			pElement[parent] = pElement[child];
			parent = child;
			child *= 2;
		}
		pElement[parent] = *pTemp;
	}
	return pReturn;
}

ArrayMinHeap::~ArrayMinHeap()
{
}

void ArrayMinHeap::deleteArrayMinHeap()
{
	if (pElement)
	{
		SAFE_DELETE(pElement);
	}
}

void ArrayMinHeap::insertMinHeapAH(HeapNode element)
{
	if (currentElementCount == maxElementCount)
	{
		std::cout << "heap full\n";
		return;
	}

	currentElementCount++;
	int i(currentElementCount);
	while ((i != 1) && (element.key < pElement[i / 2].key))
	{
		pElement[i] = pElement[i / 2];
		i /= 2;
	}

	pElement[i] = element;
}

HeapNode* ArrayMinHeap::deleteMinHeapAH()
{
	HeapNode* pReturn = nullptr;
	HeapNode* pTemp = nullptr;

	int i(0), parent(0), child(0);

	if (currentElementCount > 0)
	{
		pReturn = new HeapNode();
		*pReturn = pElement[1];

		i = currentElementCount;
		pTemp = &pElement[i];
		currentElementCount--;

		parent = 1;
		child = 2;
		while (child <= currentElementCount)
		{
			if ((child < currentElementCount)
				&& (pElement[child].key > pElement[child + 1].key))
			{
				child++;
			}

			if (pTemp->key <= pElement[child].key)
			{
				break;
			}

			pElement[parent] = pElement[child];
			parent = child;
			child *= 2;
		}
		pElement[parent] = *pTemp;
	}
	return pReturn;
}
