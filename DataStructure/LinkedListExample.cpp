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