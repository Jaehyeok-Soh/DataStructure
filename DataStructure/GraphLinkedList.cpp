#include "pch.h"
#include "GraphLinkedList.h"

bool GraphLinkedList::addLLElment(int position, GraphListNode node)
{
	bool ret = false;

	if (position >= 0 && position <= currentElementCount)
	{
		GraphListNode* newNode = new GraphListNode();
		newNode = &node;

		if (pHead == nullptr)
		{
			pHead, pTail = newNode;
			currentElementCount++;
			ret = true;
			return ret;
		}

		if (position == 0)
		{
			newNode->pNext = pHead;
			pHead->pPrev = newNode;
			pHead = newNode;
		}
		else if (position == currentElementCount)
		{
			newNode->pPrev = pTail;
			pTail->pNext = newNode;
			pTail = newNode;
		}
		else
		{
			GraphListNode* currentNode = pHead;
			for (auto i = 0; i < position; i++)
			{
				currentNode = currentNode->pNext;
			}

			newNode->pNext = currentNode;
			newNode->pPrev = currentNode->pPrev;
			currentNode->pPrev->pNext = newNode;
			currentNode->pPrev = newNode;
		}

		currentElementCount++;
		ret = true;
	}
	else
	{
		std::cout << "error, out of index\n";
	}

	return ret;
}

bool GraphLinkedList::removeLLElement(int position)
{
	bool ret = false;

	if (!pHead || !pTail)
	{
		return ret;
	}

	if (position >= 0 && position < currentElementCount)
	{
		GraphListNode* tempNode(nullptr);

		if (pHead == pTail)
		{
			tempNode = pHead;
			pHead = pTail = nullptr;
		}
		else if (position == 0)
		{
			tempNode = pHead;
			pHead->pNext->pPrev = nullptr;
			pHead = pHead->pNext;
		}
		else if (position == currentElementCount - 1)
		{
			tempNode = pTail;
			pTail->pPrev->pNext = nullptr;
			pTail = pTail->pPrev;
		}
		else
		{
			GraphListNode* currentNode = pHead;
			for (auto i = 0; i < position; i++)
				currentNode = currentNode->pNext;

			tempNode = currentNode;
			currentNode->pPrev->pNext = tempNode->pNext;
			currentNode->pNext->pPrev = tempNode->pPrev;
		}

		SAFE_DELETE(tempNode);

		currentElementCount--;
		ret = true;
	}
	else
	{
		std::cout << "error, out of index\n";
	}

	return ret;
}
