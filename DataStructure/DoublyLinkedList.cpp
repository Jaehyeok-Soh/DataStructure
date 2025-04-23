#include "pch.h"
#include "DoublyLinkedList.h"

DoublyListNode::DoublyListNode()
	: data(), prev(nullptr), next(nullptr){}
DoublyListNode::DoublyListNode(int _data)
	: data(_data), prev(nullptr), next(nullptr){}
DoublyListNode::~DoublyListNode(){}

DoublyList::DoublyList() 
	: currentElementCount(0), pHead(nullptr), pTail(nullptr){}
DoublyList::~DoublyList() { clearDoublyList(); }

bool DoublyList::addDLElement(int position, int data)
{
	bool ret = false;

	DoublyListNode* newNode(nullptr);
	
	if (position >= 0 && position <= currentElementCount)
	{
		newNode = new DoublyListNode(data);
		if (!newNode)
		{
			std::cout << "error, allocate memory\n";
			return ret;
		}

		if (!pHead)
		{
			pHead = pTail = newNode;
		}
		else if (position == 0)
		{
			pHead->prev = newNode;
			newNode->next = pHead;
			pHead = newNode;
		}
		else if(position == currentElementCount)
		{
			pTail->next = newNode;
			newNode->prev = pTail;
			pTail = newNode;
		}
		else
		{
			DoublyListNode* currentNode = pHead;
			for (auto i = 0; i < position; i++)
				currentNode = currentNode->next;

			newNode->next = currentNode;
			newNode->prev = currentNode->prev;
			currentNode->prev->next = newNode;
			currentNode->prev = newNode;
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

bool DoublyList::removeDLElement(int position)
{
	bool ret = false;

	if (!pHead || !pTail)
	{
		return ret;
	}

	if (position >= 0 && position < currentElementCount)
	{
		DoublyListNode* tempNode(nullptr);

		if (pHead == pTail)
		{
			tempNode = pHead;
			pHead = pTail = nullptr;
		}
		else if (position == 0)
		{
			tempNode = pHead;
			pHead->next->prev = nullptr;
			pHead = pHead->next;
		}
		else if (position == currentElementCount - 1)
		{
			tempNode = pTail;
			pTail->prev->next = nullptr;
			pTail = pTail->prev;
		}
		else
		{
			DoublyListNode* currentNode = pHead;
			for (auto i = 0; i < position; i++)
				currentNode = currentNode->next;

			tempNode = currentNode;
			currentNode->prev->next = tempNode->next;
			currentNode->next->prev = tempNode->prev;
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

void DoublyList::clearDoublyList()
{
	while (currentElementCount > 0)
	{
		removeDLElement(0);
	}
}

DoublyListNode* DoublyList::getDLElement(int position)
{
	DoublyListNode* pReturn = nullptr;
	DoublyListNode* currentNode = pHead;

	if (position >= 0 && position < currentElementCount)
	{
		currentNode = pHead;
		for (auto i = 0; i < position; i++)
		{
			currentNode = currentNode->next;
		}
		pReturn = currentNode;
	}
	else
	{
		std::cout << "error, out of index\n";
	}

	return pReturn;
}

void DoublyList::displayDoublyList()
{
	std::cout << "current element count : " << currentElementCount << std::endl;
	if (currentElementCount > 0)
	{
		for (auto i = 0; i < currentElementCount; i++)
		{
			std::cout << "[" << i << "] : " << getDLElement(i)->data << std::endl;
		}
	}
	else
	{
		std::cout << "list is empty\n";
	}
}
