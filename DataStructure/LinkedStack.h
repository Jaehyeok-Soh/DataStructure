#pragma once

struct StackNode
{
	char data;
	struct StackNode* next;
	
	StackNode();
};

class LinkedStack
{
	int currentElementCount;
	StackNode* pTopElement;

	LinkedStack();
	bool pushLS(StackNode element);
	StackNode* popLS();
	StackNode* peekLS();
	void deleteLinkedStack();
	bool isLinkedStackFull();
	bool isLinkedStackEmpty();
};