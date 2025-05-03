#include "pch.h"
#include "BintreeLinkedStack.h"

BintreeLinkedStackNode::BintreeLinkedStackNode(BinTreeNode _data)
{
}

bool BintreeLinkedStackNode::pushLSBinTreeNode(BinTreeNode* _data)
{
	return false;
}

BintreeLinkedStack::~BintreeLinkedStack()
{
	deleteLinkedStack();
}

bool BintreeLinkedStack::pushLS(BinTreeNode* element)
{
	bool ret = false;
	BintreeLinkedStackNode* pNode = nullptr;

	pNode = new BintreeLinkedStackNode();
	pNode->data = element;
	
	if (pNode)
	{
		if (pTop != nullptr)
		{
			pNode->next = pTop;
		}

		pTop = pNode;

		currentElementCount++;
		ret = true;
	}

	return ret;
}

BintreeLinkedStackNode* BintreeLinkedStack::popLS()
{
	BintreeLinkedStackNode* pReturn = nullptr;

	if (currentElementCount != 0)
	{
		pReturn = pTop;
		pTop = pTop->next;
		pReturn->next = nullptr;

		currentElementCount--;
	}

	return pReturn;
}

void BintreeLinkedStack::deleteLinkedStack()
{
	BintreeLinkedStackNode* current = pTop;
	BintreeLinkedStackNode* delNode = nullptr;

	while (current != nullptr)
	{
		delNode = current;
		current = current->next;
		SAFE_DELETE(delNode);
	}
}
