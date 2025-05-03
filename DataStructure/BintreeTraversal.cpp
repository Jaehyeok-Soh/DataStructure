#include "pch.h"
#include "Bintree.h"
#include "BintreeLinkedStack.h"
#include "BintreeLinkedQueue.h"

void BinTree::preorderTraversalBinTree()
{
	BintreeLinkedStack stack;
	BintreeLinkedStackNode* pStackNode;
	BinTreeNode* currentTreeNode = pRootNode;

	if (!currentTreeNode)
	{
		return;
	}

	stack.pushLS(currentTreeNode);
	while (1)
	{
		if (stack.currentElementCount == 0)
		{
			break;
		}
		else
		{
			pStackNode = stack.popLS();
			if (pStackNode)
			{
				currentTreeNode = pStackNode->data;
				std::cout << currentTreeNode->data;
				if (currentTreeNode->pRightChild)
				{
					stack.pushLS(currentTreeNode->pRightChild);
				}
				if (currentTreeNode->pLeftChild)
				{
					stack.pushLS(currentTreeNode->pLeftChild);
				}

				SAFE_DELETE(pStackNode);
			}
		}
	}
	stack.deleteLinkedStack();
}

void BinTree::inorderTraversalBintree()
{
	BintreeLinkedStack stack;
	BintreeLinkedStackNode* pStackNode;
	BinTreeNode* currentTreeNode = nullptr;

	if (!pRootNode)
	{
		return;
	}

	currentTreeNode = pRootNode;
	while (1)
	{
		for (; currentTreeNode != nullptr; currentTreeNode = currentTreeNode->pLeftChild)
		{
			stack.pushLS(currentTreeNode);
		}

		if (stack.currentElementCount == 0)
		{
			break;
		}
		else
		{
			pStackNode = stack.popLS();
			if (pStackNode)
			{
				currentTreeNode = pStackNode->data;
				std::cout << currentTreeNode->data << " ";
				currentTreeNode = currentTreeNode->pRightChild;

				SAFE_DELETE(currentTreeNode);
			}
		}
	}

	stack.deleteLinkedStack();
}

void BinTree::postorderTraversalBintree()
{
}

void BinTree::levelOrderTraversalBintree()
{
	BintreeLinkedQueue queue;
	BintreeLinkedQueueNode* pQueueNode = nullptr;
	BinTree* pSubTree = nullptr;
	BinTreeNode* currentTreeNode = pRootNode;

	queue.enqueueLQ(currentTreeNode);
	while (true)
	{
		if (queue.currentElementCount == 0)
		{
			break;
		}
		else
		{
			pQueueNode = queue.dequeue();
			if (pQueueNode)
			{
				currentTreeNode = pQueueNode->data;
				if (currentTreeNode)
				{
					std::cout << currentTreeNode->data << " ";
					if (currentTreeNode->pLeftChild)
					{
						queue.enqueueLQ(currentTreeNode->pLeftChild);
					}
					else
					{
						queue.enqueueLQ(currentTreeNode->pRightChild);
					}

					SAFE_DELETE(pQueueNode);
				}
			}
		}
	}
	queue.deleteLinkedQueue();
}