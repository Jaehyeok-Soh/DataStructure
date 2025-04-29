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
	void displayArrayStack();

	ArrayStack(int size);
private:
	int maxElementCount;
	int currentElementCount;
	ArrayStackNode* pElement;
};