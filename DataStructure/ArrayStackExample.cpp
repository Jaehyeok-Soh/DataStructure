#include "pch.h"
#include "ArrayStack.h"

int ArrayStackExample()
{
	ArrayStack arrayStack = ArrayStack(6);
	ArrayStackNode* pNode = nullptr;
	char value = 0;

	ArrayStackNode node1 = { 'A' };
	ArrayStackNode node2 = { 'B' };
	ArrayStackNode node3 = { 'C' };
	ArrayStackNode node4 = { 'D' };

	arrayStack.pushAS(node1);
	arrayStack.pushAS(node2);
	arrayStack.pushAS(node3);
	arrayStack.pushAS(node4);

	if (pNode)
	{
		pNode = arrayStack.popAS();
		std::cout << "pop value : " << pNode->data << std::endl;
		SAFE_DELETE(pNode);
	}
	else
	{
		std::cout << "error, stack is empty\n";
	}
	
	arrayStack.displayArrayStack();

	pNode = arrayStack.peekAS();
	if (pNode)
	{
		std::cout << "peek value : " << pNode->data << std::endl;
	}
	else
	{
		std::cout << "empty stack\n";
	}

	arrayStack.displayArrayStack();

	return 0;
}