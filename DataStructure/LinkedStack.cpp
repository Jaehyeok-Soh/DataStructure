#include "pch.h"
#include "LinkedStack.h"

StackNode::StackNode(char cValue)
{
	data = cValue;
	next = nullptr;
}

LinkedStack::LinkedStack()
{
	currentElementCount = 0;
	pTopElement = nullptr;
}

LinkedStack::~LinkedStack()
{
	deleteLinkedStack();
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

void LinkedStack::displayLinkedStack()
{
	int i(1);
	StackNode* current = nullptr;
	if (pTopElement)
	{
		std::cout << "current stack count : " << currentElementCount << std::endl;
	}

	current = pTopElement;
	while (current)
	{
		std::cout << currentElementCount - i << '-' << current->data << std::endl;
		i++;
		current = current->next;
	}
}

