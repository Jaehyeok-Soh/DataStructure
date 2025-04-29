#include "pch.h"
#include "LinkedStack.h"

int LinkedStackExample()
{
	LinkedStack linkedStack;
	StackNode* pNode = nullptr;

	StackNode node1 = StackNode('A');
	StackNode node2 = StackNode('B');
	StackNode node3 = StackNode('C');
	StackNode node4 = StackNode('D');

	linkedStack.pushLS(node1);
	linkedStack.pushLS(node2);
	linkedStack.pushLS(node3);
	linkedStack.pushLS(node4);

	linkedStack.displayLinkedStack();

	pNode = linkedStack.popLS();
	if (pNode)
	{
		std::cout << "Pop-" << pNode->data << std::endl;
		SAFE_DELETE(pNode);
	}
	else
	{
		std::cout << "Pop-null" << std::endl;
	}

	linkedStack.displayLinkedStack();

	pNode = linkedStack.peekLS();
	if (pNode)
	{
		std::cout << "Peek-" << pNode->data << std::endl;
		SAFE_DELETE(pNode);
	}
	else
	{
		std::cout << "Peek-null" << std::endl;
	}

	linkedStack.displayLinkedStack();

	linkedStack.deleteLinkedStack();

	//LinkedStack util
	char sourceStr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char successExprStr[] = "{(A * B) / C} - {(D + E) && (F - G)}";
	char failExprStr[] = "{(A * B) / C - {(D + E) && (F - G))}";
	bool checkResult = false;

	char* pReverseStr = linkedStack.reverseString(sourceStr);
	if (pReverseStr)
	{
		std::cout << sourceStr << "=>" << pReverseStr << std::endl;
		SAFE_DELETE(pReverseStr);
	}

	checkResult = linkedStack.checkBracketMatching(successExprStr);
	if (checkResult)
	{
		std::cout << "SUCCESS, " << successExprStr;
	}
	else
	{
		std::cout << "FAIL, " << successExprStr;
	}

	checkResult = linkedStack.checkBracketMatching(failExprStr);
	if (checkResult)
	{
		std::cout << "SUCCESS, " << failExprStr;
	}
	else
	{
		std::cout << "FAIL, " << failExprStr;
	}

	return 0;
}