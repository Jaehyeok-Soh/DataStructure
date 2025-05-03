#include "pch.h"
#include "ArrayHeap.h"

int HeapExample()
{
	int maxHeapSize = 20;

	ArrayMaxHeap heap1 = ArrayMaxHeap(maxHeapSize);
	HeapNode* pNode;

	heap1.insertMaxHeapAH(HeapNode(10));
	heap1.insertMaxHeapAH(HeapNode(40));
	heap1.insertMaxHeapAH(HeapNode(30));
	heap1.insertMaxHeapAH(HeapNode(20));
	heap1.insertMaxHeapAH(HeapNode(50));

	std::cout << "Max Heap\n";
	heap1.displayArrayHeap();

	pNode = heap1.deleteMaxHeapAH();
	if (pNode)
	{
		std::cout << "deleteMaxHeapAH-" << pNode->key << std::endl;
		SAFE_DELETE(pNode);
	}

	std::cout << "Max Heap\n";
	heap1.displayArrayHeap();

	heap1.deleteArrayMaxHeap();

	return 0;
}