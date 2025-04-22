#pragma once
typedef struct CircularListNodeType
{
	int data;
	CircularListNodeType* pLink;
} CircularListNode;

class CircularList
{
public :
	int currentElementCount = 0;
	CircularListNode* pHead;

	~CircularList();

	bool addCLElement(int position, CircularListNode element);
	bool removeCLElement(int position);
	void clearCircularList();
	CircularListNode* getCLElement(int position);
	void displayCircularList();
};