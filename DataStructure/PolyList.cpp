#include "pch.h"
#include "LinkedList.h"

bool LinkedList::addPolyNodeLast(float coef, int degree)
{
	bool ret = false;

	ListNode node = { 0 , };
	node.coef = coef;
	node.degree = degree;

	ret = addLLElement(currentElementCount, node);
	return ret;
}

bool LinkedList::addPolyNodeLast(LinkedList* pList, float coef, int degree)
{
	bool ret = false;

	if (!pList)
		return ret;

	ListNode node = { 0 , };
	node.coef = coef;
	node.degree = degree;

	ret = pList->addLLElement(pList->currentElementCount, node);
}

LinkedList* LinkedList::polyAdd(LinkedList* pList)
{
	LinkedList* pReturn = nullptr;
	ListNode* pNodeA(nullptr), * pNodeB(nullptr);
	float coefSum = 0;

	if (pList)
	{
		pReturn = new LinkedList;
		if (!pReturn)
		{
			std::cout << "error, allocate memory\n";
			return nullptr;
		}

		pNodeA = headerNode.pLink;
		pNodeB = pList->headerNode.pLink;
		
		while (pNodeA && pNodeB)
		{
			int degreeA = pNodeA->degree;
			int degreeB = pNodeB->degree;
			
			if (degreeA > degreeB)
			{
				coefSum = pNodeA->coef;
				//TODO: check error
				addPolyNodeLast(pReturn, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
			}
			else if (degreeA == degreeB)
			{
				coefSum = pNodeA->coef + pNodeB->coef;
				addPolyNodeLast(pReturn, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
				pNodeB = pNodeB->pLink;
			}
			else
			{
				coefSum = pNodeB->coef;
				addPolyNodeLast(pReturn, coefSum, degreeB);
				pNodeB = pNodeB->pLink;
			}
		}

		while (pNodeA)
		{
			coefSum = pNodeA->coef;
			addPolyNodeLast(pReturn, coefSum, pNodeA->degree);
			pNodeA = pNodeA->pLink;
		}

		while (pNodeB)
		{
			coefSum = pNodeB->coef;
			addPolyNodeLast(pReturn, coefSum, pNodeB->degree);
			pNodeB = pNodeB->pLink;
		}
	}
	else
	{
		std::cout << "error, null polylist\n";
	}

	return pReturn;
}

void LinkedList::displayPolyList()
{
	for (auto i = 0; i < currentElementCount; i++)
	{
		ListNode* pNode = getLLElement(i);
		if (pNode)
		{
			std::cout << pNode->coef << "x^" << pNode->degree;
			if (i == currentElementCount - 1)
			{
				std::cout << std::endl;
			}
			else
			{
				std::cout << " + ";
			}
		}
	}
}

void LinkedList::displayPolyList(LinkedList* pList)
{
	if (!pList)
	{
		std::cout << "error, null polylist\n";
	}

	for (auto i = 0; i < pList->currentElementCount; i++)
	{
		ListNode* pNode = getLLElement(i);
		if (pNode)
		{
			std::cout << pNode->coef << "x^" << pNode->degree;
			if (i == pList->currentElementCount - 1)
			{
				std::cout << std::endl;
			}
			else
			{
				std::cout << " + ";
			}
		}
	}
}