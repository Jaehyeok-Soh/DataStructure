#include "pch.h"
#include "LinkedDeque.h"

int LinkedDequeExample()
{
	LinkedDeque deque = LinkedDeque();
	DequeNode* pNode = nullptr;

	deque.insertFrontLD(DequeNode('A'));
	deque.insertFrontLD(DequeNode('B'));
	deque.insertRearLD(DequeNode('C'));
	deque.insertRearLD(DequeNode('D'));
	deque.displayLinkedDeque();

	pNode = deque.deleteRearLD();
	if (pNode)
	{
		std::cout << "delete rear LD value-" << pNode->data << std::endl;
		SAFE_DELETE(pNode);
	}
	deque.displayLinkedDeque();

	pNode = deque.deleteFrontLD();
	if (pNode)
	{
		std::cout << "delete front LD value-" << pNode->data << std::endl;
		SAFE_DELETE(pNode);
	}
	deque.displayLinkedDeque();

	deque.deleteLinkedDeque();

	return 0;
}