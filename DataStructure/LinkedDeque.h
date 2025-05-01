#pragma once

class DequeNode
{
public:
	char data;
	DequeNode* next = nullptr;
	DequeNode* prev = nullptr;

	DequeNode() = default;
	DequeNode(char _data);
	~DequeNode();
};

class LinkedDeque
{
public:
	int currentElementCount;
	DequeNode* pFront;
	DequeNode* pRear;

	LinkedDeque();
	~LinkedDeque();

	bool insertFrontLD(DequeNode element);
	bool insertRearLD(DequeNode element);
	DequeNode* deleteFrontLD();
	DequeNode* deleteRearLD();
	DequeNode* peekFrontLD();
	DequeNode* peekRearLD();
	void deleteLinkedDeque();
	bool isLinkedDequeFull();
	bool isLinkedDequeEmpty();

	void displayLinkedDeque();
};

