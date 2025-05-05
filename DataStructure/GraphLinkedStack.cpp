#include "pch.h"
#include "GraphLinkedStack.h"

GraphLinkedStackNode::GraphLinkedStackNode()
{
}

GraphLinkedStackNode::~GraphLinkedStackNode()
{
}

GraphLinkedStack::GraphLinkedStack()
{
}

GraphLinkedStack::~GraphLinkedStack()
{
	deleteLinkedStack();
}

bool GraphLinkedStack::pushLS(GraphLinkedStackNode element)
{
	bool ret = false;

	GraphLinkedStackNode* newNode = new GraphLinkedStackNode();

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

GraphLinkedStackNode* GraphLinkedStack::popLS()
{
	GraphLinkedStackNode* pReturn = nullptr;
	if (!isLinkedStackEmpty())
	{
		pReturn = pTopElement;
		pTopElement = pReturn->next;
		pReturn->next = nullptr;

		currentElementCount--;
	}

	return pReturn;
}

GraphLinkedStackNode* GraphLinkedStack::peekLS()
{
	GraphLinkedStackNode* pReturn = nullptr;

	if (!isLinkedStackEmpty())
	{
		pReturn = pTopElement;
	}

	return pReturn;
}

void GraphLinkedStack::deleteLinkedStack()
{
	GraphLinkedStackNode* current = nullptr;
	GraphLinkedStackNode* pDelNode = nullptr;

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

bool GraphLinkedStack::isLinkedStackFull()
{
	int ret = false;
	return ret;
}

bool GraphLinkedStack::isLinkedStackEmpty()
{
	return !pTopElement && currentElementCount == 0;
}

void GraphLinkedStack::displayLinkedStack()
{
	int i(1);
	GraphLinkedStackNode* current = nullptr;
	if (pTopElement)
	{
		std::cout << "current stack count : " << currentElementCount << std::endl;
	}

	current = pTopElement;
	while (current)
	{
		std::cout << currentElementCount - i << '-' << current->vertextID << std::endl;
		i++;
		current = current->next;
	}
}