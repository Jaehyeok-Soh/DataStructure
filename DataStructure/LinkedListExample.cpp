#include "pch.h"

int LinkedListExample()
{
	int arrayCount = 0;
	LinkedList list, listB;
	ListNode node;
	
		node.data = 1;
		list.addLLElement(0, node);

		node.data = 2;
		list.addLLElement(1, node);
		
		node.data = 3;
		list.addLLElement(2, node);
		
		node.data = 4;
		listB.addLLElement(0, node);

		node.data = 5;
		listB.addLLElement(1, node);

		list.iterateLinkedList();
		listB.iterateLinkedList();

		listB.reverseLinkedList();
		listB.iterateLinkedList();

		list.deleteLinkedList();
		listB.deleteLinkedList();
	
	return 0;
}

int PolyLinkedListExample()
{
	LinkedList pListA, pListB;
	LinkedList* pListC(nullptr);

	pListA.addPolyNodeLast(6, 6);
	pListA.addPolyNodeLast(4, 5);
	pListA.addPolyNodeLast(2, 2);
	pListA.displayPolyList();

	pListB.addPolyNodeLast(1, 5);
	pListB.addPolyNodeLast(2, 4);
	pListB.addPolyNodeLast(3, 2);
	pListB.addPolyNodeLast(4, 0);
	pListB.displayPolyList();

	pListC = pListA.polyAdd(&pListB);

	if (pListC)
	{
		pListC->displayPolyList();
		pListC->deleteLinkedList();
	}

	pListA.deleteLinkedList();
	pListB.deleteLinkedList();

	return 0;
}