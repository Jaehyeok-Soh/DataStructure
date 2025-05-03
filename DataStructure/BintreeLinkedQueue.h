#pragma once
#include "BinTree.h"

class BintreeLinkedQueueNode
{
public:
	BinTreeNode* data = nullptr;
	BintreeLinkedQueueNode* next = nullptr;
	BintreeLinkedQueueNode* prev = nullptr;
};

class BintreeLinkedQueue
{
public:
	int currentElementCount = 0;
	BintreeLinkedQueueNode* pFront = nullptr;
	BintreeLinkedQueueNode* pRear = nullptr;

	~BintreeLinkedQueue();

	bool enqueueLQ(BinTreeNode* element);
	BintreeLinkedQueueNode* dequeue();

	void deleteLinkedQueue();
};