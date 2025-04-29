#include "pch.h"
#include "LinkedStack.h"

ExprStackNode* ExprStackNode::Clone() const
{
	return new ExprStackNode(*this);
}

ExprStackNode::ExprStackNode(ExprToken _eData)
{
	data = _eData;
	next = nullptr;
}

ExprStackNode::~ExprStackNode()
{
}

char ExprStackNode::getCharData() const
{
	return 0;
}

ExprToken ExprStackNode::getExprData() const
{
	return data;
}

void LinkedStack::calcExpr(ExprToken* pExprTokens, int tokenCount)
{
	LinkedStack* pStack;
	StackNode* pNode1 = nullptr, * pNode2 = nullptr;
	Precedence tokenType;

	if (!pExprTokens) return;

	pStack = new LinkedStack();

	for (auto i = 0; i < tokenCount; i++)
	{
		tokenType = pExprTokens[i].type;
		if (tokenType == operand)
		{
			pStack->pushLSExprToken(pExprTokens[i]);
		}
		else
		{
			pNode2 = pStack->popLS();
			if (pNode2)
			{
				pNode1 = pStack->popLS();
				if (pNode1)
				{
					float op1 = pNode1->getExprData().value;
					float op2 = pNode2->getExprData().value;

					ExprToken newToken;
					newToken.type = operand;
					switch (tokenType)
					{
					case plus:
						newToken.value = op1 + op2;
						break;
					case minus:
						newToken.value = op1 - op2;
						break;
					case times:
						newToken.value = op1 * op2;
						break;
					case divide:
						newToken.value = op1 / op2;
						break;
					}

					pStack->pushLSExprToken(newToken);

					SAFE_DELETE(pNode1);
				}
				SAFE_DELETE(pNode2);
			}
		}
	}

	pNode1 = pStack->popLS();
	if (pNode1)
	{
		std::cout << "calculation result : " << pNode1->getExprData().value << std::endl;
		SAFE_DELETE(pNode1);
	}
	else
	{
		std::cout << "error, expression available" << std::endl;
	}

	SAFE_DELETE(pStack);
}

bool LinkedStack::pushLSExprToken(ExprToken data)
{
	ExprStackNode node = ExprStackNode(data);
	return pushLS(node);
}

void LinkedStack::convertInfexToPostFix(ExprToken* pExprTokens, int tokenCount)
{
	LinkedStack* pStack = nullptr;
	StackNode* pNode = nullptr;
	Precedence tokenType;
	Precedence inStackTokenType;

	if (!pExprTokens) return;

	pStack = new LinkedStack();

	for (auto i = 0; i < tokenCount; i++)
	{
		tokenType = pExprTokens[i].type;
		switch (tokenType)
		{
		case operand:
			std::cout << pExprTokens[i].value << std::endl;
			break;

		case rparen:
			pNode = pStack->popLS();
			while (pNode && pNode->getExprData().type != lparen)
			{
				printToken(pNode->getExprData());
				SAFE_DELETE(pNode);

				pNode = pStack->popLS();
			}
			if (pNode) SAFE_DELETE(pNode);
			break;

		default:
			while (pStack->isLinkedStackEmpty() == false)
			{
				inStackTokenType = pStack->peekLS()->getExprData().type;
				if (outStackPrecedence(tokenType) <= inStackPrecedence(inStackTokenType))
				{
					pNode = pStack->popLS();
					if (pNode)
					{
						printToken(pNode->getExprData());
						SAFE_DELETE(pNode);
					}
				}
				else
				{
					break;
				}
			}
			pStack->pushLSExprToken(pExprTokens[i]);
			break;
		}
	}

	while (!pStack->isLinkedStackEmpty())
	{
		pNode = pStack->popLS();
		if (pNode)
		{
			printToken(pNode->getExprData());
			SAFE_DELETE(pNode);
		}
	}

	SAFE_DELETE(pStack);
}

int LinkedStack::inStackPrecedence(Precedence oper)
{
	switch (oper)
	{
	case lparen:
		return 0;
	case rparen:
		return 4;
	case times:
	case divide:
		return 2;
	case plus:
	case minus:
		return 1;
	}
	return -1;
}

int LinkedStack::outStackPrecedence(Precedence oper)
{
	switch (oper)
	{
	case lparen:
		return 5;
	case rparen:
		return 4;
	case times:
	case divide:
		return 2;
	case plus:
	case minus:
		return 1;
	}
	return -1;
}

void LinkedStack::printToken(ExprToken element)
{
	switch (element.type)
	{
	case lparen:
		std::cout << "(\n";
		break;
	case rparen:
		std::cout << ")\n";
		break;
	case times:
		std::cout << "*\n";
		break;
	case divide:
		std::cout << "/\n";
		break;
	case plus:
		std::cout << "+\n";
		break;
	case minus:
		std::cout << "-\n";
		break;
	case operand:
		std::cout << element.value << std::endl;
		break;
	}
}
