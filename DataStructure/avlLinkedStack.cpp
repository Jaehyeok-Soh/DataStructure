#include "pch.h"
#include "avlLinkedStack.h"

bool avlLinkedStack::pushLS(avlStackNode element)
{
	bool ret = false;
	avlStackNode* newNode = &element;

	if (pTop == nullptr)
	{
		pTop = newNode;
	}
	else
	{
		newNode->pNext = pTop;
		pTop = newNode;
	}

	ret = true;
	currentElementCount++;

	return ret;
}

avlStackNode* avlLinkedStack::popLS()
{
	avlStackNode* pReturn = nullptr;

	if (pTop != nullptr)
	{
		pReturn = pTop;
		pTop = pTop->pNext;
		pReturn->pNext = nullptr;

		currentElementCount--;
	}
	else
	{
		std::cout << "error, stack is empty\n";
	}

	return pReturn;
}

avlStackNode* avlLinkedStack::peekLS()
{
	avlStackNode* pReturn = nullptr;

	if (pTop != nullptr)
	{
		pReturn = pTop;
	}
	else
	{
		std::cout << "error, stack is empty\n";
	}

	return pReturn;
}

void avlLinkedStack::deleteLinkedStack()
{
	avlStackNode* pNode = nullptr;
	avlStackNode* pDelNode = nullptr;

	if (pTop != nullptr)
	{
		pNode = pTop;
		while (pNode != nullptr)
		{
			pDelNode = pNode;
			pNode = pNode->pNext;
			SAFE_DELETE(pDelNode);
		}
	}
}

bool avlLinkedStack::isLinkedStackFull()
{
	bool ret = false;
	return ret;
}

bool avlLinkedStack::isLinkedStackEmpty()
{
	bool ret = currentElementCount == 0;

	return ret;
}

avlTreeNode* avlLinkedStack::popAVLTreeNode()
{
	avlTreeNode* pReturn = nullptr;

	if (isLinkedStackEmpty() == false)
	{
		avlStackNode* pNode = popLS();
		if (pNode != nullptr)
		{
			pReturn = pNode->data;
			SAFE_DELETE(pNode);
		}
	}

	return pReturn;
}

bool avlLinkedStack::pushAVLTreeNode(avlTreeNode* data)
{
	avlStackNode node;
	node.data = data;
	
	return pushLS(node);
}

avlTreeNode* avlLinkedStack::peekAVLTreeNode()
{
	avlTreeNode* pReturn = nullptr;

	if (isLinkedStackEmpty() == false)
	{
		avlStackNode* pNode = peekLS();
		if (pNode != nullptr)
		{
			pReturn = pNode->data;
		}
	}

	return pReturn;
}
