#include "pch.h"
#include "ArrayQueue.h"

int ArrayQueueExample()
{
	ArrayQueue Queue = ArrayQueue(4);
	ArrayQueueNode* pNode = nullptr;
	char value = 0;

	Queue.enqueueAQChar('A');
	Queue.enqueueAQChar('B');
	Queue.enqueueAQChar('C');
	Queue.enqueueAQChar('D');

	Queue.displayArrayQueue();

	pNode = Queue.dequeueAQ();
	if (pNode)
	{
		std::cout << "Dequeue Value-" << pNode->data << std::endl;
		SAFE_DELETE(pNode);
	}

	Queue.displayArrayQueue();
	pNode = Queue.peekAQ();
	if (pNode)
	{
		std::cout << "Peek Value-" << pNode->data << std::endl;
	}
	Queue.displayArrayQueue();

	Queue.enqueueAQChar('E');

	Queue.displayArrayQueue();

	return 0;
}