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
	DoublyListNode* currentNode = pHead;
	
	if (position >= 0 && position <= currentElementCount)
	{
		newNode = new DoublyListNode(data);
		if (!newNode)
		{
			std::cout << "error, allocate memory\n";
			return ret;
		}

		for (auto i = 0; i < position; i++)
		{
			currentNode = currentNode->next;
		}
		newNode->prev = currentNode;
		newNode->next = currentNode->next;
		currentNode->next = newNode;
		currentNode->next->prev = newNode;

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
	int arrayCount = currentElementCount;

	if (position >= 0 && position < arrayCount)
	{
		DoublyListNode* tempNode(nullptr);
		DoublyListNode* currentNode = pHead;

		for (auto i = 0; i < position; i++)
		{
			currentNode = currentNode->next;
		}
		tempNode = currentNode->next;

		currentNode->next = tempNode->next;
		tempNode->next->prev = currentNode;
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
