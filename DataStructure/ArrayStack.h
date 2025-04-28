#pragma once

struct ArrayStackNode
{
	char data;
};

class ArrayStack
{
public:
	bool pushAS(ArrayStackNode element);
	ArrayStackNode* popAS();
	ArrayStackNode* peekAS();
	void deleteArrayStack();
	bool isArrayStackFull();
	bool isArrayStackEmpty();

	ArrayStack();
private:
	int maxElementCount;
	int currentElementCount;
	ArrayStackNode* pElement;
};