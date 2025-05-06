#pragma once

class GraphVertex
{
public:
	int vertexID = 0;
	int weight = 0;
};

class GraphListNode
{
public:
	GraphVertex data;
	GraphListNode* pNext = nullptr;;
	GraphListNode* pPrev = nullptr;
};

class GraphLinkedList
{
public:
	int currentElementCount = 0;

	GraphListNode* pHead = nullptr;
	GraphListNode* pTail = nullptr;

	GraphLinkedList();

	bool addLLElment(int position, GraphListNode node);
	bool removeLLElement(int position);
};