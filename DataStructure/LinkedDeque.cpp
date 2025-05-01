#include "pch.h"
#include "LinkedDeque.h"

DequeNode::DequeNode(char _data)
{
	data = _data;
	next = nullptr;
	prev = nullptr;
}

DequeNode::~DequeNode()
{
}

LinkedDeque::LinkedDeque()
{
	currentElementCount = 0;
	pFront = nullptr;
	pRear = nullptr;
}

LinkedDeque::~LinkedDeque()
{
	deleteLinkedDeque();
}

bool LinkedDeque::insertFrontLD(DequeNode element)
{
	bool ret = false;

	DequeNode* pNode = new DequeNode();
	*pNode = element;

	if (isLinkedDequeEmpty())
	{
		pFront = pNode;
		pRear = pNode;
		
		ret = true;
	}
	else
	{
		pFront->prev = pNode;
		pNode->next = pFront;
		pFront = pNode;
	
		ret = true;
	}
	currentElementCount++;

	return ret;
}

bool LinkedDeque::insertRearLD(DequeNode element)
{
	bool ret = false;

	DequeNode* pNode = new DequeNode();
	*pNode = element;

	if (isLinkedDequeEmpty())
	{
		pFront = pNode;
		pRear = pNode;

		ret = true;
	}
	else
	{
		pRear->next = pNode;
		pNode->prev = pRear;
		pRear = pNode;

		ret = true;
	}
	currentElementCount++;

	return ret;
}

DequeNode* LinkedDeque::deleteFrontLD()
{
	DequeNode* pReturn = nullptr;

	if (!isLinkedDequeEmpty())
	{
		pReturn = pFront;
		pFront = pFront->next;
		pReturn->next = nullptr;

		currentElementCount--;

		if (isLinkedDequeEmpty())
		{
			pFront = nullptr;
			pRear = nullptr;
		}
		else
		{
			pFront->prev = nullptr;
		}
	}
	else
	{
		std::cout << "error, deque is empty" << std::endl;
	}

	return pReturn;
}

DequeNode* LinkedDeque::deleteRearLD()
{
	DequeNode* pReturn = nullptr;

	if (!isLinkedDequeEmpty())
	{
		pReturn = pRear;
		pRear = pRear->prev;
		pReturn->prev = nullptr;
		
		currentElementCount--;

		if (isLinkedDequeEmpty())
		{
			pFront = nullptr;
			pRear = nullptr;
		}
		else
		{
			pRear->next = nullptr;
		}
	}
	else
	{
		std::cout << "error, deque is empty" << std::endl;
	}

	return pReturn;
}

DequeNode* LinkedDeque::peekFrontLD()
{
	DequeNode* pReturn = nullptr;

	if (!isLinkedDequeEmpty())
	{
		pReturn = pFront;
	}

	return pReturn;
}

DequeNode* LinkedDeque::peekRearLD()
{
	DequeNode* pReturn = nullptr;

	if (!isLinkedDequeEmpty())
	{
		pReturn = pFront;
	}

	return pReturn;
}

void LinkedDeque::deleteLinkedDeque()
{
	DequeNode* current = nullptr;
	DequeNode* pDelNode = nullptr;

	current = pFront;
	while (current)
	{
		pDelNode = current;
		current = current->next;
		SAFE_DELETE(pDelNode);
	}

	currentElementCount = 0;
	pFront = nullptr;
	pRear = nullptr;
}

bool LinkedDeque::isLinkedDequeFull()
{
	bool ret = false;
	return ret;
}

bool LinkedDeque::isLinkedDequeEmpty()
{
	bool ret = false;

	if (currentElementCount == 0)
	{
		ret = true;
	}

	return ret;
}

void LinkedDeque::displayLinkedDeque()
{
	int i(0);
	DequeNode* current = nullptr;

	std::cout << "current element count : " << currentElementCount << std::endl;
	current = pFront;
	while (current)
	{
		std::cout << i << "-" << current->data << std::endl;
		i++;
		current = current->next;
	}
}
