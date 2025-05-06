#include "pch.h"
#include "GraphLinkedQueue.h"
GraphLinkedQueueNode::GraphLinkedQueueNode(int _vertexID)
{
	vertexID = _vertexID;
	next = nullptr;
	prev = nullptr;
}

GraphLinkedQueueNode::~GraphLinkedQueueNode()
{
}

GraphLinkedQueue::GraphLinkedQueue()
{
	currentElementCount = 0;
	pFront = nullptr;
	pRear = nullptr;
}

GraphLinkedQueue::~GraphLinkedQueue()
{
	deleteLinkedDeque();
}

bool GraphLinkedQueue::insertFrontLD(GraphLinkedQueueNode element)
{
	bool ret = false;

	GraphLinkedQueueNode* pNode = new GraphLinkedQueueNode();
	*pNode = element;

	if (isLinkedDequeEmpty())
	{
		pFront = pNode;
		pRear = pNode;

		ret = true;
	}
	else
	{
		pFront->prev = pNode;
		pNode->next = pFront;
		pFront = pNode;

		ret = true;
	}
	currentElementCount++;

	return ret;
}

bool GraphLinkedQueue::insertRearLD(GraphLinkedQueueNode element)
{
	bool ret = false;

	GraphLinkedQueueNode* pNode = new GraphLinkedQueueNode();
	*pNode = element;

	if (isLinkedDequeEmpty())
	{
		pFront = pNode;
		pRear = pNode;

		ret = true;
	}
	else
	{
		pRear->next = pNode;
		pNode->prev = pRear;
		pRear = pNode;

		ret = true;
	}
	currentElementCount++;

	return ret;
}

GraphLinkedQueueNode* GraphLinkedQueue::deleteFrontLD()
{
	GraphLinkedQueueNode* pReturn = nullptr;

	if (!isLinkedDequeEmpty())
	{
		pReturn = pFront;
		pFront = pFront->next;
		pReturn->next = nullptr;

		currentElementCount--;

		if (isLinkedDequeEmpty())
		{
			pFront = nullptr;
			pRear = nullptr;
		}
		else
		{
			pFront->prev = nullptr;
		}
	}
	else
	{
		std::cout << "error, deque is empty" << std::endl;
	}

	return pReturn;
}

GraphLinkedQueueNode* GraphLinkedQueue::deleteRearLD()
{
	GraphLinkedQueueNode* pReturn = nullptr;

	if (!isLinkedDequeEmpty())
	{
		pReturn = pRear;
		pRear = pRear->prev;
		pReturn->prev = nullptr;

		currentElementCount--;

		if (isLinkedDequeEmpty())
		{
			pFront = nullptr;
			pRear = nullptr;
		}
		else
		{
			pRear->next = nullptr;
		}
	}
	else
	{
		std::cout << "error, deque is empty" << std::endl;
	}

	return pReturn;
}

GraphLinkedQueueNode* GraphLinkedQueue::peekFrontLD()
{
	GraphLinkedQueueNode* pReturn = nullptr;

	if (!isLinkedDequeEmpty())
	{
		pReturn = pFront;
	}

	return pReturn;
}

GraphLinkedQueueNode* GraphLinkedQueue::peekRearLD()
{
	GraphLinkedQueueNode* pReturn = nullptr;

	if (!isLinkedDequeEmpty())
	{
		pReturn = pFront;
	}

	return pReturn;
}

void GraphLinkedQueue::deleteLinkedDeque()
{
	GraphLinkedQueueNode* current = nullptr;
	GraphLinkedQueueNode* pDelNode = nullptr;

	current = pFront;
	while (current)
	{
		pDelNode = current;
		current = current->next;
		SAFE_DELETE(pDelNode);
	}

	currentElementCount = 0;
	pFront = nullptr;
	pRear = nullptr;
}

bool GraphLinkedQueue::isLinkedDequeFull()
{
	bool ret = false;
	return ret;
}

bool GraphLinkedQueue::isLinkedDequeEmpty()
{
	bool ret = false;

	if (currentElementCount == 0)
	{
		ret = true;
	}

	return ret;
}

void GraphLinkedQueue::displayLinkedDeque()
{
	int i(0);
	GraphLinkedQueueNode* current = nullptr;

	std::cout << "current element count : " << currentElementCount << std::endl;
	current = pFront;
	while (current)
	{
		std::cout << i << "-" << current->vertexID << std::endl;
		i++;
		current = current->next;
	}
}