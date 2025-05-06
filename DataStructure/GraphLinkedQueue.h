#pragma once
class GraphLinkedQueueNode
{
public:
	int vertexID;
	GraphLinkedQueueNode* next = nullptr;
	GraphLinkedQueueNode* prev = nullptr;

	GraphLinkedQueueNode() = default;
	GraphLinkedQueueNode(int _vertexID);
	~GraphLinkedQueueNode();
};

class GraphLinkedQueue
{
public:
	int currentElementCount;
	GraphLinkedQueueNode* pFront;
	GraphLinkedQueueNode* pRear;

	GraphLinkedQueue();
	~GraphLinkedQueue();

	bool insertFrontLD(GraphLinkedQueueNode element);
	bool insertRearLD(GraphLinkedQueueNode element);
	GraphLinkedQueueNode* deleteFrontLD();
	GraphLinkedQueueNode* deleteRearLD();
	GraphLinkedQueueNode* peekFrontLD();
	GraphLinkedQueueNode* peekRearLD();
	void deleteLinkedDeque();
	bool isLinkedDequeFull();
	bool isLinkedDequeEmpty();

	void displayLinkedDeque();
};