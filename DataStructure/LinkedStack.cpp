#include "pch.h"
#include "LinkedStack.h"

StackNode::StackNode()
{
	data = '\0';
	next = nullptr;
}

LinkedStack::LinkedStack()
{
	currentElementCount = 0;
	pTopElement = nullptr;
}

bool LinkedStack::pushLS(StackNode element)
{
	bool ret = false;

	StackNode* newNode = new StackNode();
	if (newNode)
	{
		*newNode = element;

		if (pTopElement == nullptr)
		{
			pTopElement = newNode;
		}
		else
		{
			newNode->next = pTopElement;
			pTopElement = newNode;
		}

		currentElementCount++;

		ret = true;
	}

	return ret;
}

StackNode* LinkedStack::popLS()
{
	StackNode* pReturn = nullptr;
	if (!isLinkedStackEmpty())
	{
		pReturn = pTopElement;
		pTopElement = pReturn->next;
		pReturn->next = nullptr;

		currentElementCount--;
	}

	return pReturn;
}

StackNode* LinkedStack::peekLS()
{
	StackNode* pReturn = nullptr;
	
	if (!isLinkedStackEmpty())
	{
		pReturn = pTopElement;
	}

	return pReturn;
}

void LinkedStack::deleteLinkedStack()
{
	StackNode* current = nullptr;
	StackNode* pDelNode = nullptr;

	if (!pTopElement)
	{
		current = pTopElement;
		while (current)
		{
			pDelNode = current;
			current = current->next;
			SAFE_DELETE(pDelNode);
		}

		currentElementCount = 0;
	}
	
}

bool LinkedStack::isLinkedStackFull()
{
	int ret = false;
	return ret;
}

bool LinkedStack::isLinkedStackEmpty()
{
	return !pTopElement && currentElementCount == 0;
}

