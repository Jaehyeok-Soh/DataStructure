#pragma once
class QueueNode
{
public:
	char data;
	QueueNode* next;

	QueueNode() = default;
	QueueNode(char _data);
};

class LinkedQueue
{
public:
	int currentElementCount;
	QueueNode* pFront;
	QueueNode* pRear;

	LinkedQueue();
	~LinkedQueue();

	bool enqueueLQ(QueueNode element);
	QueueNode* dequeueLQ();
	QueueNode* peekLQ();
	void deleteLinkedQueue();
	bool isLinkedQueueFull();
	bool isLinkedQueueEmpty();

	void displayLinkedQueue();
};

