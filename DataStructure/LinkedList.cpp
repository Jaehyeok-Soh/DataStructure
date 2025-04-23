#include "pch.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
	currentElementCount = 0;
}

LinkedList::~LinkedList()
{
	clearLinkedList();
}

bool LinkedList::addLLElement(int position, ListNode element)
{
	bool ret = false;
	ListNode* pPreNode = nullptr;
	ListNode* pNewNode = nullptr;
	if (position >= 0 && position <= currentElementCount)
	{
		pNewNode = new ListNode;
		if (pNewNode)
		{
			*pNewNode = element;
			pNewNode->pLink = nullptr;

			if (position == 0)
			{
				headerNode = *pNewNode;
			}

			pPreNode = &(headerNode);
			for (auto i = 0; i < position; i++)
			{
				pPreNode = pPreNode->pLink;
			}

			pNewNode->pLink = pPreNode->pLink;
			pPreNode->pLink = pNewNode;

			currentElementCount++;

			ret = true;
		}
		else
		{
			std::cout << "error, allocate memory _2\n";
			return ret;
		}
	}
	else
	{
		std::cout << "error, out of index\n";
	}

	return ret;
}

bool LinkedList::removeLLElement(int position)
{
	bool ret = false;
	ListNode* pNode = nullptr;
	ListNode* pDelNode = nullptr;
	if (position >= 0 && position < currentElementCount)
	{
		pNode = &headerNode;
		for (auto i = 0; i < position; i++)
		{
			pNode = pNode->pLink;
		}

		pDelNode = pNode->pLink;
		pNode->pLink = pDelNode->pLink;
		SAFE_DELETE(pDelNode);

		currentElementCount--;

		ret = true;
	}
	else
	{
		std::cout << "error, out of index\n";
	}

	return ret;
}

ListNode* LinkedList::getLLElement(int position)
{
	ListNode* pReturn = nullptr;
	ListNode* pCurrentNode = nullptr;
	if (position >= 0 && position < currentElementCount)
	{
		pCurrentNode = &headerNode;
		for (auto i = 0; i <= position; i++)
		{
			pCurrentNode = pCurrentNode->pLink;
		}
		pReturn = pCurrentNode;
	}

	return pReturn;
}

void LinkedList::clearLinkedList()
{
	while (!isEmpty())
	{
		removeLLElement(0);
	}
}

void LinkedList::deleteLinkedList()
{
	clearLinkedList();
}

bool LinkedList::isEmpty()
{
	return currentElementCount == 0;
}

void LinkedList::DisplayLinkedList()
{
	std::cout << "current element count : " << currentElementCount << std::endl;
	for (auto i = 0; i < currentElementCount; i++)
	{
		std::cout << i << ", " << getLLElement(i)->data << std::endl;
	}
}
