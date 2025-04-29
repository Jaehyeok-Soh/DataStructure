#pragma once

struct StackNode
{
public :
	char data;
	struct StackNode* next;
	
	StackNode() = default;
	StackNode(char _cValue);
};

class LinkedStack
{
public :
	int currentElementCount;
	StackNode* pTopElement;

	LinkedStack();
	~LinkedStack();

	bool pushLS(StackNode element);
	StackNode* popLS();
	StackNode* peekLS();
	void deleteLinkedStack();
	bool isLinkedStackFull();
	bool isLinkedStackEmpty();
	void displayLinkedStack();
};