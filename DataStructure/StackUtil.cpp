#include "pch.h"
#include "LinkedStack.h"
#include <string>
//strlen()
//strcpy
//memcpy

char* LinkedStack::reverseString(char* pSource)
{
	char* pReturn = nullptr;
	LinkedStack linkedStack;
	StackNode* pNode = nullptr;
	int size(0);

	if (!pSource)
		return nullptr;

	size = strlen(pSource);
	if (size)
		return nullptr;
	
	pReturn = new char[size];
	if (!pReturn)
		return nullptr;

	CharStackNode node;
	for (auto i = 0; i < size; i++)
	{
		node.data = pSource[i];
		linkedStack.pushLS(node);
	}

	for (auto i = 0; i < size; i++)
	{
		pNode = linkedStack.popLS();
		if (pNode)
		{
			pReturn[i] = pNode->getCharData();
			SAFE_DELETE(pNode);
		}
	}

	pReturn[size] = '\0';

	linkedStack.deleteLinkedStack();

	return pReturn;
}

bool LinkedStack::checkBracketMatching(char* pSource)
{
	bool ret = false;
	int size(0);
	char symbol('\0'), checkSymbol('\0');

	LinkedStack linkedStack;
	StackNode* pNode = nullptr;

	if (!pSource)
	{
		ret = true;
		return ret;
	}

	size = strlen(pSource);
	if (!size)
	{
		ret = true;
		return ret;
	}

	CharStackNode node;
	for (auto i = 0; i < size && ret == true; i++)
	{
		symbol = pSource[i];
		switch (symbol)
		{
		case '(':
		case '[':
		case '{':
			node.data = symbol;
			linkedStack.pushLS(node);
			break;

		case ')':
		case ']':
		case '}':
			pNode = linkedStack.popLS();
			if (!pNode)
			{
				ret = false;
				break;
			}
			else
			{
				checkSymbol = pNode->getCharData();
				if ((symbol == '}' && checkSymbol == '{')
					|| (symbol == ']' && checkSymbol == '[')
					|| (symbol == ')' && checkSymbol == '('))
				{
					//Right case
				}
				else
				{
					ret = false;
				}
				SAFE_DELETE(pNode);
			}
			break;
		}
	}

	if (!linkedStack.isLinkedStackEmpty())
	{
		ret = false;
	}

	return ret;
}