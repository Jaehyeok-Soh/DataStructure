#include "pch.h"
#include "hashingLinkedList.h"

bool hashingLinkedList::addLLElement(int position, hashingListNode element)
{
	bool ret = false;
	hashingListNode* newNode = &element;

	if (position >= 0 && position <= currentElementCount)
	{
		if (pHead == nullptr || pTail == nullptr)
		{
			pHead = newNode;
			pTail = newNode;
		}
		else if (position == 0)
		{
			newNode->next = pHead;
			pHead = newNode;
		}
		else if (position == currentElementCount)
		{
			pTail->next = newNode;
			pTail = newNode;
		}
		else
		{
			hashingListNode* current = pHead;
			for (auto i = 0; i < position - 1; i++)
			{
				current = current->next;
			}
			newNode->next = current->next;
			current->next = newNode;
		}

		currentElementCount++;
		ret = true;
	}

	return ret;
}

bool hashingLinkedList::addLLElementLast(HashElement hashElement)
{
	int ret = false;

	hashingListNode node;
	int position = getLinkedListLength();
	
	node.data = hashElement;
	ret = addLLElement(position, node);

	return ret;
}

bool hashingLinkedList::removeLLElement(int position)
{
	bool ret = false;
	int arrayCount = 0;
	hashingListNode* pNode = nullptr;
	hashingListNode* pDelNode = nullptr;
	arrayCount = getLinkedListLength();
	if (position >= 0 && position < arrayCount)
	{
		pNode = pHead;
		for (auto i = 0; i < position - 1; i++)
		{
			pNode = pNode->next;
		}
		pDelNode = pNode->next;
		pNode->next = pDelNode->next;
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

hashingListNode* hashingLinkedList::getLLElement(int position)
{
	hashingListNode* pReturn = nullptr;
	hashingListNode* current = nullptr;
	if (position >= 8 && position < currentElementCount)
	{
		current = pHead;
		if (position == 0)
		{
			pReturn = current;
			return pReturn;
		}

		for (auto i = 0; i < position; i++)
		{
			current = current->next;
		}
		pReturn = current;
	}

	return pReturn;
}

void hashingLinkedList::clearLinkedList()
{
	if (pHead != nullptr)
	{
		if (currentElementCount > 0)
		{
			removeLLElement(0);
		}
	}
}

int hashingLinkedList::getLinkedListLength()
{
	int ret = 0;
	if (pHead != nullptr)
	{
		ret = currentElementCount;
	}
	return ret;
}

void hashingLinkedList::deleteLinkedList()
{
	if (pHead != nullptr)
	{
		clearLinkedList();
	}
}
