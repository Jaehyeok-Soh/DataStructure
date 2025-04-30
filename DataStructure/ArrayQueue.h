#pragma once
class ArrayQueueNode
{
public:
	char data;

	ArrayQueueNode() = default;
	ArrayQueueNode(char _data);
};

class ArrayQueue
{
public :
	int maxElementCount;
	int currentElementCount;
	int front;
	int rear;
	ArrayQueueNode* pElement;

	ArrayQueue();
	ArrayQueue(int _maxElementCount);
	~ArrayQueue();

	bool enqueueAQ(ArrayQueueNode element);
	ArrayQueueNode* dequeueAQ();
	ArrayQueueNode* peekAQ();
	void deleteArrayQueue();
	bool isArrayQueueFull();
	bool isArrayQueueEmpty();
	void displayArrayQueue();
	bool enqueueAQChar(char data);
};