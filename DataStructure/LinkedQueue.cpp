#include "pch.h"
#include "LinkedQueue.h"

QueueNode::QueueNode(char _data)
{
	data = _data;
	next = nullptr;
}


LinkedQueue::LinkedQueue()
{
	currentElementCount = 0;
	pFront = nullptr;
	pRear = nullptr;
}

LinkedQueue::~LinkedQueue()
{
	deleteLinkedQueue();
}

bool LinkedQueue::enqueueLQ(QueueNode element)
{
	bool ret = false;

	QueueNode* pNode = nullptr;
	pNode = new QueueNode();
	if (pNode)
	{
		*pNode = element;
		pNode->next = nullptr;

		if (isLinkedQueueEmpty())
		{
			pFront = pNode;
			pRear = pNode;
		}
		else
		{
			pRear->next = pNode;
			pRear = pNode;
		}
		currentElementCount++;
		ret = true;
	}
	else
	{
		std::cout << "error, allocate memory" << std::endl;
	}

	return ret;
}

QueueNode* LinkedQueue::dequeueLQ()
{
	QueueNode* pReturn = nullptr;

	if (!isLinkedQueueEmpty())
	{
		pReturn = pFront;
		pFront = pFront->next;
		pReturn->next = nullptr;
		currentElementCount--;
		if (isLinkedQueueEmpty())
		{
			pRear = nullptr;
		}
	}
	else
	{
		std::cout << "error, Queue is empty" << std::endl;
	}

	return pReturn;
}

QueueNode* LinkedQueue::peekLQ()
{
	QueueNode* pReturn = nullptr;

	if (!isLinkedQueueEmpty())
	{
		pReturn = pFront;
	}

	return pReturn;
}

void LinkedQueue::deleteLinkedQueue()
{
	QueueNode* pNode = nullptr;
	QueueNode* pDelNode = nullptr;

	pNode = pFront;
	while (pNode)
	{
		pDelNode = pNode;
		pNode = pNode->next;

		SAFE_DELETE(pDelNode);
	}
	pFront = nullptr;
	pRear = nullptr;
}

bool LinkedQueue::isLinkedQueueFull()
{
	bool ret = false;
	return ret;
}

bool LinkedQueue::isLinkedQueueEmpty()
{
	bool ret = false;

	if (currentElementCount == 0)
	{
		ret = true;
	}

	return ret;
}

void LinkedQueue::displayLinkedQueue()
{
	int i(0);
	QueueNode* current = nullptr;
	std::cout << "Current element count : " << currentElementCount << std::endl;

	current = pFront;
	while (current)
	{
		std::cout << i << "-" << current->data << std::endl;
		i++;
		current = current->next;
	}
}
