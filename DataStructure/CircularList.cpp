#include "pch.h"
#include "CircularList.h"

CircularList::~CircularList()
{
	clearCircularList();
}

bool CircularList::addCLElement(int position, CircularListNode element)
{
	bool ret = false;
	CircularListNode* pNewNode, * currentNode = nullptr;
	if (position >= 0 && position <= currentElementCount)
	{
		pNewNode = new CircularListNode;
		if (pNewNode == nullptr)
		{
			std::cout << "error, allocate memory";
			return ret;
		}

		*pNewNode = element;
		pNewNode->pLink = nullptr;

		if (position == 0)
		{
			if (currentElementCount == 0)
			{
				pHead = pNewNode;
				pNewNode->pLink = pNewNode;
			}
			else
			{
				currentNode = pHead;
				while (currentNode->pLink != pHead)
				{
					currentNode = currentNode->pLink;
				}
				pHead = pNewNode;
				pNewNode->pLink = currentNode->pLink;
				currentNode->pLink = pNewNode;
			}
		}
		else
		{
			currentNode = pHead;
			for (auto i = 0; i < position; i++)
			{
				currentNode = currentNode->pLink;
			}
			pNewNode->pLink = currentNode->pLink;
			currentNode->pLink = pNewNode;
		}
		currentElementCount++;
		ret = true;
	}

	return ret;
}

bool CircularList::removeCLElement(int position)
{
	bool ret = false;
	CircularListNode* pDelNode, * currentNode = nullptr;
	if (position >= 0 && position < currentElementCount)
	{
		currentNode = pHead;
		if (position == 0)
		{
			if (currentElementCount == 1)
			{
				SAFE_DELETE(currentNode);
			}
			else
			{
				pDelNode = pHead;
				while (currentNode->pLink != pHead)
				{
					currentNode = currentNode->pLink;
				}
				currentNode->pLink = pDelNode->pLink;
				pHead = pDelNode->pLink;
				SAFE_DELETE(pDelNode);
			}
		}
		else
		{
			for (auto i = 0; i < position; i++)
			{
				currentNode = currentNode->pLink;
			}
			pDelNode = currentNode->pLink;
			currentNode->pLink = pDelNode->pLink;
			SAFE_DELETE(pDelNode);
		}
		currentElementCount--;
		ret = true;
	}
	else
	{
		std::cout << "error, out of index\n";
	}

	return ret;
}

void CircularList::clearCircularList()
{
	while (currentElementCount > 0)
	{
		removeCLElement(0);
	}
}

CircularListNode* CircularList::getCLElement(int position)
{
	CircularListNode* currentNode = nullptr;
	if (position >= 0 && position < currentElementCount)
	{
		currentNode = pHead;
		for (auto i = 0; i < position; i++)
		{
			currentNode = currentNode->pLink;
		}
	}

	return currentNode;
}

void CircularList::displayCircularList()
{
	std::cout << "current element count : " << currentElementCount << std::endl;
	if (currentElementCount)
	{
		for (auto i = 0; i < currentElementCount; i++)
		{
			std::cout << "[i] : " << getCLElement(i)->data << std::endl;
		}
	}
	else
	{
		std::cout << "error, list empty\n";
	}
}