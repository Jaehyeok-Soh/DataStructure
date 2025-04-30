#include "pch.h"
#include "ArrayQueue.h"

ArrayQueue::ArrayQueue()
{
}

ArrayQueue::ArrayQueue(int _maxElementCount)
{
	maxElementCount = _maxElementCount;
	currentElementCount = 0;
	front = -1;
	rear = -1;
	pElement = new ArrayQueueNode[_maxElementCount];
}

ArrayQueue::~ArrayQueue()
{
	deleteArrayQueue();
}

bool ArrayQueue::enqueueAQ(ArrayQueueNode element)
{
	bool ret = false;

	if (isArrayQueueFull() == false)
	{
		rear++;
		pElement[rear] = element;
		currentElementCount++;
		ret = true;
	}
	else
	{
		std::cout << "error, queue is full" << std::endl;
	}

	return ret;
}

ArrayQueueNode* ArrayQueue::dequeueAQ()
{
	ArrayQueueNode* pReturn = nullptr;

	if (isArrayQueueEmpty() == false)
	{
		pReturn = new ArrayQueueNode();
		if (pReturn)
		{
			front++;
			pReturn->data = pElement[front].data;
			currentElementCount--;
		}
		else
		{
			std::cout << "error, allocate memory" << std::endl;
		}
	}

	return pReturn;
}

ArrayQueueNode* ArrayQueue::peekAQ()
{
	ArrayQueueNode* pReturn = nullptr;

	if (isArrayQueueEmpty() == false)
	{
		pReturn = &pElement[front + 1];
	}

	return pReturn;
}

void ArrayQueue::deleteArrayQueue()
{
	SAFE_DELETE_ARRAY(pElement);
}

bool ArrayQueue::isArrayQueueFull()
{
	bool ret = false;

	if (currentElementCount == maxElementCount || rear == maxElementCount - 1)
	{
		ret = true;
	}

	return ret;
}

bool ArrayQueue::isArrayQueueEmpty()
{
	bool ret = false;

	if (currentElementCount == 0)
	{
		ret = true;
	}

	return ret;
}

void ArrayQueue::displayArrayQueue()
{
	std::cout << "Queue size : " << maxElementCount << " Current element count : " << currentElementCount << std::endl;
	for (auto i = front + 1; i <= rear; i++)
	{
		std::cout << i << "-" << pElement[i].data << std::endl;
	}
}

bool ArrayQueue::enqueueAQChar(char data)
{
	ArrayQueueNode node = ArrayQueueNode(data);

	return enqueueAQ(node);
}

ArrayQueueNode::ArrayQueueNode(char _data)
{
	data = _data;
}
