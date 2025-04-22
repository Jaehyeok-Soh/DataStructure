#include "pch.h"
#include "LinkedList.h"

LinkedList* LinkedList::createLinkedList()
{
	LinkedList* pReturn = nullptr;
	int i = 0;

	pReturn = new LinkedList;
	if (pReturn)
	{
		memset(pReturn, 0, sizeof(LinkedList));
	}
	else
	{
		std::cout << "error, allocate memory\n";
	}

	return pReturn;
}

bool LinkedList::addLLElement(LinkedList* pList, int position, ListNode element)
{
	bool ret = false;
	int i = 0;
	ListNode* pPreNode = nullptr;
	ListNode* pNewNode = nullptr;
	if (pList)
	{
		if (position >= 0 && position <= pList->currentElementCount)
		{
			pNewNode = new ListNode;
			if (pNewNode)
			{
				*pNewNode = element;
				pNewNode->pLink = nullptr;

				pPreNode = &(pList->headerNode);
				for (i = 0; i < position; i++)
				{
					pPreNode = pPreNode->pLink;
				}

				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;

				pList->currentElementCount++;

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

bool LinkedList::removeLLElement(LinkedList* pList, int position)
{
	return false;
}

ListNode* LinkedList::getLLElement(LinkedList* pList, int position)
{
	return nullptr;
}

void LinkedList::clearLinkedList(LinkedList* pList)
{
}

int LinkedList::getLinkedListLength(LinkedList* pList)
{
	return 0;
}

void LinkedList::deleteLinkedList(LinkedList* pList)
{
}
