#include "pch.h"
#include "LinkedList.h"

ListNode::~ListNode()
{
	SAFE_DELETE(pLink);
}

bool LinkedList::addLLElement(int position, ListNode element)
{
	bool ret = false;
	ListNode* pPreNode = nullptr;
	ListNode* pNewNode = nullptr;
	if (this)
	{
		if (position >= 0 && position <= currentElementCount)
		{
			pNewNode = new ListNode;
			if (pNewNode)
			{
				*pNewNode = element;
				pNewNode->pLink = nullptr;

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
	}

	return ret;
}

bool LinkedList::removeLLElement(int position)
{
	bool ret = false;
	int arrayCount = 0;
	ListNode* pNode = nullptr;
	ListNode* pDelNode = nullptr;
	if (this)
	{
		arrayCount = getLinkedListLength();
		if (position >= 0 && position < arrayCount)
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
	}

	return ret;
}

ListNode* LinkedList::getLLElement(int position)
{
	ListNode* pReturn = nullptr;
	ListNode* pNode = nullptr;
	if (this)
	{
		if (position >= 0 && position < currentElementCount)
		{
			pNode = &headerNode;
			for (auto i = 0; i <= position; i++)
			{
				pNode = pNode->pLink;
			}
			pReturn = pNode;
		}
	}

	return pReturn;
}

void LinkedList::clearLinkedList()
{
	if (this)
	{
		if (currentElementCount > 0)
		{
			removeLLElement(0);
		}
	}
}

int LinkedList::getLinkedListLength()
{
	int ret = 0;
	if (this)
	{
		ret = currentElementCount;
	}

	return ret;
}

void LinkedList::deleteLinkedList()
{
	if (this)
	{
		clearLinkedList();
	}
}

bool LinkedList::isEmpty()
{
	bool ret = false;
	if (this)
	{
		if (currentElementCount == 0)
		{
			ret = true;
		}
	}

	return ret;
}

void LinkedList::DisplayLinkedList()
{
	if (this)
	{
		std::cout << "current element count : " << currentElementCount << std::endl;
		for (auto i = 0; i < currentElementCount; i++)
		{
			std::cout << i << ', ' << getLLElement(i)->data << std::endl;
		}
	}
	else
	{
		std::cout << "list empty\n";
	}
}
