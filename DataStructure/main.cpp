#include "pch.h"

int main()
{
	DoublyListNode node;
	DoublyList list;

	list.addDLElement(0, 1);
	list.addDLElement(1, 2);
	list.addDLElement(2, 3);
	list.addDLElement(3, 4);
	list.addDLElement(2, 5);

	list.displayDoublyList();

	return 0;
}