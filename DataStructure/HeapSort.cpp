#include "pch.h"
#include "ArrayHeap.h"

void heapSort(int value[], int count)
{
	ArrayMinHeap heap = ArrayMinHeap(count);
	HeapNode node;

	for (auto i = 0; i < count; i++)
	{
		node.key = value[i];
		heap.insertMinHeapAH(node);
	}

	for (auto i = 0; i < count; i++)
	{
		HeapNode* pNode = heap.deleteMinHeapAH();
		if (pNode != nullptr)
		{
			value[i] = pNode->key;
			SAFE_DELETE(pNode);
		}
	}

	heap.deleteArrayMinHeap();
}