#include "pch.h"
#include "LinkedStack.h"
#include "MapDef.h"

int LinkedStackExample()
{
	LinkedStack linkedStack;
	StackNode* pNode = nullptr;

	CharStackNode node1 = CharStackNode('A');
	CharStackNode node2 = CharStackNode('B');
	CharStackNode node3 = CharStackNode('C');
	CharStackNode node4 = CharStackNode('D');

	linkedStack.pushLS(node1);
	linkedStack.pushLS(node2);
	linkedStack.pushLS(node3);
	linkedStack.pushLS(node4);

	linkedStack.displayLinkedStack();

	pNode = linkedStack.popLS();
	if (pNode)
	{
		std::cout << "Pop-" << pNode->getCharData() << std::endl;
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
		std::cout << "Peek-" << pNode->getCharData() << std::endl;
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

	//LinkedStack Expression
	//2 3 4 + 5 * -
	ExprToken* pExprTokens = new ExprToken[7];
	pExprTokens[0].type = operand;
	pExprTokens[0].value = 2;
	pExprTokens[1].type = operand;
	pExprTokens[1].value = 3;
	pExprTokens[2].type = operand;
	pExprTokens[2].value = 4;
	pExprTokens[3].type = plus;
	pExprTokens[3].value = 0;
	pExprTokens[4].type = operand;
	pExprTokens[4].value = 5;
	pExprTokens[5].type = times;
	pExprTokens[5].value = 0;
	pExprTokens[6].type = minus;
	pExprTokens[6].value = 0;

	std::cout << "Expression: 2 3 4 + 5 * - \n";
	linkedStack.calcExpr(pExprTokens, 7);
	SAFE_DELETE_ARRAY(pExprTokens);

	//2 - (3 + 4) * 5
	pExprTokens = new ExprToken[9];
	pExprTokens[0].type = operand;
	pExprTokens[0].value = 2;
	pExprTokens[1].type = minus;
	pExprTokens[1].value = 0;
	pExprTokens[2].type = lparen;
	pExprTokens[2].value = 0;
	pExprTokens[3].type = operand;
	pExprTokens[3].value = 3;
	pExprTokens[4].type = plus;
	pExprTokens[4].value = 0;
	pExprTokens[5].type = operand;
	pExprTokens[5].value = 4;
	pExprTokens[6].type = rparen;
	pExprTokens[6].value = 0;
	pExprTokens[7].type = times;
	pExprTokens[7].value = 0;
	pExprTokens[8].type = operand;
	pExprTokens[8].value = 5;

	std::cout << "Infix Expression : 2 - (3 + 4) * 5 \n";
	std::cout << "Postfix Expression : \n";

	linkedStack.convertInfexToPostFix(pExprTokens, 9);
	SAFE_DELETE_ARRAY(pExprTokens);

	//map
	MapPosition startPos, endPos;
	int mazeArray[HEIGHT][WIDTH] = {
		{0, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 0}
	};

	startPos.x = 0;
	startPos.y = 0;
	endPos.x = 7;
	endPos.y = 7;

	linkedStack.printMaze(mazeArray);

	linkedStack.findPath(mazeArray, startPos, endPos);

	linkedStack.showPath(mazeArray);

	linkedStack.deleteLinkedStack();

	return 0;
}