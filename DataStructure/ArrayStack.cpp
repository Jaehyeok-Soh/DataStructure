#include "pch.h"

#include "ArrayStack.h"

bool ArrayStack::pushAS(ArrayStackNode element)
{
	int ret = false;

	if (!isArrayStackFull())
	{
		pElement[currentElementCount] = element;
		currentElementCount++;
		ret = true;
	}
	else
	{
		std::cout << "error, stack is full\n";
	}

	return ret;
}

ArrayStackNode* ArrayStack::popAS()
{
	ArrayStackNode* pReturn = nullptr;

	if (!isArrayStackEmpty())
	{
		pReturn = new ArrayStackNode;
		*pReturn = pElement[currentElementCount - 1];
		currentElementCount--;
	}
	return pReturn;
}

ArrayStackNode* ArrayStack::peekAS()
{
	ArrayStackNode* pReturn = nullptr;

	if (!isArrayStackEmpty())
	{
		pReturn = &pElement[currentElementCount - 1];
	}

	return pReturn;
}

void ArrayStack::deleteArrayStack()
{
	SAFE_DELETE_ARRAY(pElement);
	currentElementCount = 0;
	maxElementCount = 0;
}

bool ArrayStack::isArrayStackFull()
{
	bool ret = false;

	if (currentElementCount == maxElementCount)
	{
		ret = true;
	}

	return ret;
}

bool ArrayStack::isArrayStackEmpty()
{
	bool ret = false;

	if (currentElementCount == 0)
	{
		ret = true;
	}

	return ret;
}

void ArrayStack::displayArrayStack()
{
	std::cout << "stack size : " << maxElementCount << '\t' << "현재 노드 개수" << currentElementCount << std::endl;

	for (auto i = maxElementCount - 1; i >= currentElementCount; i--)
	{
		std::cout << i << "-empty\n";
	}

	for (auto i = currentElementCount - 1; i >= 0; i--)
	{
		std::cout << i << '-' << pElement[i].data << std::endl;
	}
}

ArrayStack::ArrayStack(int size)
{
	if (size)
	{
		"error, min length\n";
		return;
	}

	maxElementCount = size;
	currentElementCount = 0;
	pElement = new ArrayStackNode[size];
}