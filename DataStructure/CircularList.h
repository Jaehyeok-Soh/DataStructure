#pragma once
typedef struct CircularListNodeType
{
	int data;
	CircularListNode* pLink;
} CircularListNode;

class CircularList
{
public :
	int currentElementCount;
	CircularListNode* pLink;

	CircularList();
	~CircularList();
};