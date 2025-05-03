#pragma once

class HeapNode
{
public:
	int key = 0;
	char data = '\0';

	HeapNode() = default;
	HeapNode(int _key);
};

//arrayMaxHeap, arrayMinHeap
class ArrayHeap
{
public:
	int maxElementCount = 0;
	int currentElementCount = 0;
	HeapNode* pElement = nullptr;

	ArrayHeap() = default;
	ArrayHeap(int elementCount);
	virtual ~ArrayHeap();

	void displayArrayHeap();
};

class ArrayMaxHeap : public ArrayHeap
{
public:
	ArrayMaxHeap(int elementCount) : ArrayHeap(elementCount) {};
	~ArrayMaxHeap() override;

	void deleteArrayMaxHeap();
	void insertMaxHeapAH(HeapNode element);
	HeapNode* deleteMaxHeapAH();
};

class ArrayMinHeap : public ArrayHeap
{
public:
	~ArrayMinHeap() override;
};