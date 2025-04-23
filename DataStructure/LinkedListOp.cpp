#include "pch.h"
#include "LinkedList.h"
void LinkedList::iterateLinkedList()
{
	ListNode* pNode = nullptr;
	int count = 0;
	pNode = headerNode.pLink;
	while (pNode != nullptr)
	{
		std::cout << "[" << count << "] " << pNode->data << std::endl;
		count++;
		pNode = pNode->pLink;
	}

	std::cout << "node count : " << count << std::endl;
}

void LinkedList::concatLinkedList(LinkedList* pList)
{
	ListNode* pNodeA(nullptr);
	ListNode* pNodeB(nullptr);

	if (pList)
	{
		pNodeA = headerNode.pLink;
		while (pNodeA->pLink)
		{
			pNodeA = pNodeA->pLink;
		}
		pNodeA->pLink = pList->headerNode.pLink;
		currentElementCount += pList->currentElementCount;

		pList->clearLinkedList();
		pList->currentElementCount = 0;
	}
}

void LinkedList::reverseLinkedList()
{
	ListNode* next(nullptr);
	ListNode* current(headerNode.pLink);
	ListNode* prev(nullptr);
	while (current)
	{
		next = current->pLink;
		current->pLink = prev;
		prev = current;
		current = next;
	}
	headerNode.pLink = prev;
}