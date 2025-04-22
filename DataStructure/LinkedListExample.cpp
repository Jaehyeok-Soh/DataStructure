#include "pch.h"

int LinkedListExample()
{
	int arrayCount = 0;
	LinkedList list;
	ListNode node;
	
		node.data = 1;
		list.addLLElement(0, node);

		node.data = 3;
		list.addLLElement(1, node);
		
		node.data = 5;
		list.addLLElement(2, node);
		list.DisplayLinkedList();

		list.removeLLElement(0);
		list.DisplayLinkedList();

		list.deleteLinkedList();
	
	return 0;
}