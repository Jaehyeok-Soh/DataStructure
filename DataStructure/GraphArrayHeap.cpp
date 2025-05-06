#include "pch.h"
#include "GraphArrayHeap.h"
GraphHeapNode::GraphHeapNode(int _key, int _fromVertexID, int _toVertexID)
{
	key = _key;
	fromVertexID = _fromVertexID;
	toVertexID = _toVertexID;
}

GraphArrayHeap::GraphArrayHeap(int elementCount)
{
	maxElementCount = elementCount;
	pElement = new GraphHeapNode[elementCount + 1];
}

GraphArrayHeap::~GraphArrayHeap()
{
}

void GraphArrayHeap::displayArrayHeap()
{
	for (int i = 1; i <= currentElementCount; i++)
	{
		std::cout << i << "-" << pElement[i].key << std::endl;
	}
}

GraphArrayMaxHeap::~GraphArrayMaxHeap()
{
	deleteArrayMaxHeap();
}

void GraphArrayMaxHeap::deleteArrayMaxHeap()
{
	if (pElement)
	{
		SAFE_DELETE(pElement);
	}
}

void GraphArrayMaxHeap::insertMaxHeapAH(GraphHeapNode element)
{
	if (currentElementCount == maxElementCount)
	{
		std::cout << "heap full\n";
		return;
	}

	currentElementCount++;
	int i(currentElementCount);
	while ((i != 1) && (element.key > pElement[i / 2].key))
	{
		pElement[i] = pElement[i / 2];
		i /= 2;
	}

	pElement[i] = element;
}

GraphHeapNode* GraphArrayMaxHeap::deleteMaxHeapAH()
{
	GraphHeapNode* pReturn = nullptr;
	GraphHeapNode* pTemp = nullptr;

	int i(0), parent(0), child(0);

	if (currentElementCount > 0)
	{
		pReturn = new GraphHeapNode();
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

GraphArrayMinHeap::~GraphArrayMinHeap()
{
	deleteArrayMinHeap();
}

void GraphArrayMinHeap::deleteArrayMinHeap()
{
	if (pElement)
	{
		SAFE_DELETE(pElement);
	}
}

void GraphArrayMinHeap::insertMinHeapAH(GraphHeapNode element)
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

GraphHeapNode* GraphArrayMinHeap::deleteMinHeapAH()
{
	GraphHeapNode* pReturn = nullptr;

	int i(0), parent(0), child(0);

	if (currentElementCount > 0)
	{
		pReturn = new GraphHeapNode();
		*pReturn = pElement[1];

		i = currentElementCount;
		GraphHeapNode pTemp = pElement[i];
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

			if (pTemp.key <= pElement[child].key)
			{
				break;
			}

			pElement[parent] = pElement[child];
			parent = child;
			child *= 2;
		}
		pElement[parent] = pTemp;
	}
	return pReturn;
}
