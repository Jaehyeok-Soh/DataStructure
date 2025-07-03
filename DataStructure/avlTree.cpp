#include "pch.h"

#include "avlTree.h"

bool avlTree::insertNodeAVL(avlTreeNodeData element)
{
	bool ret = false;

	avlTreeNode* pParentNode = nullptr;
	avlTreeNode* pNewNode = nullptr;
	avlLinkedStack* pStack = new avlLinkedStack();

	pParentNode = pRoot;
	while (pParentNode != nullptr)
	{
		pStack->pushAVLTreeNode(pParentNode);
		if (element.key == pParentNode->data.key)
		{
			std::cout << "error, key conflict\n";
			ret = false;
			return ret;
		}
		else if (element.key < pParentNode->data.key)
		{
			if (pParentNode->pLeft == nullptr)
			{
				break;
			}
			else
			{
				pParentNode = pParentNode->pLeft;
			}
		}
		else
		{
			if (pParentNode->pRight == nullptr)
			{
				break;
			}
			else
			{
				pParentNode = pParentNode->pRight;
			}
		}
	}

	pNewNode = new avlTreeNode();
	pNewNode->data = element;
	pNewNode->height = 1;

	if (pParentNode == nullptr)
	{
		pRoot = pNewNode;
	}
	else
	{
		if (pNewNode->data.key < pParentNode->data.key)
		{
			pParentNode->pLeft = pNewNode;
		}
		else
		{
			pParentNode->pRight = pNewNode;
		}
	}

	ret = true;

	balanceAVLTree(pStack);

	pStack->deleteLinkedStack();
	SAFE_DELETE(pStack);

	return ret;
}

void avlTree::balanceAVLTree(avlLinkedStack* pStack)
{
	avlTreeNode* pParentNode = nullptr;
	avlTreeNode* pNode = nullptr;
	avlTreeNode* pChildNode = nullptr;
	avlTreeNode* pNewNode = nullptr;

	if (pRoot == nullptr || pStack == nullptr)
	{
		return;
	}

	while (pStack->isLinkedStackEmpty() == false)
	{
		pNode = pStack->popAVLTreeNode();
		if (pNode != nullptr)
		{
			pNode->updateHeightAndBalanceAVL();
			if (pNode->balance >= -1 && pNode->balance <= 1)
			{
				continue;
			}

			//leftBalance - rightBalance
			//(n) >> left big
			//-(n) >> right big
			if (pNode->balance > 1)//2
			{
				pChildNode = pNode->pLeft;
				//LL
				if (pChildNode->balance > 0)
				{
					pNewNode = pNode->rotateLLAVLTree();
				}
				//LR
				else
				{
					pNewNode = pNode->rotateLRAVLTree();
				}
			}
			else if (pNode->balance < -1)//-2
			{
				pChildNode = pNode->pRight;
				//RR
				if (pChildNode->balance < 0)
				{
					pNewNode = pNode->rotateRRAVLTree();
				}
				//RL
				else
				{
					pNewNode = pNode->rotateRLAVLTree();
				}
			}

			pParentNode = pStack->peekAVLTreeNode();
			if (pParentNode != nullptr)
			{
				if (pParentNode->pLeft == pNode)
				{
					pParentNode->pLeft = pNewNode;
				}
				else
				{
					pParentNode->pRight = pNewNode;
				}
			}
			else
			{
				pRoot = pNewNode;
			}
		}
	}
}

bool avlTree::deleteNodeAVL(int key)
{
	bool ret = false;

	avlTreeNode* pDelNode = nullptr;
	avlTreeNode* pParentNode = nullptr;
	avlTreeNode* pPredecessor = nullptr;
	avlTreeNode* pSuccessor = nullptr;
	avlTreeNode* pChild = nullptr;
	avlLinkedStack* pStackMain = new avlLinkedStack();
	avlLinkedStack* pStackSub = new avlLinkedStack();

	pDelNode = pRoot;
	while (pDelNode != nullptr)
	{
		if (key == pDelNode->data.key)
		{
			break;
		}
		pParentNode = pDelNode;
		pStackMain->pushAVLTreeNode(pParentNode);

		if (key < pDelNode->data.key)
		{
			pDelNode = pDelNode->pLeft;
		}
		else
		{
			pDelNode = pDelNode->pRight;
		}
	}
	
	if (pDelNode == nullptr)
	{
		std::cout << "error, not found key\n";
		ret = false;
		return ret;
	}

	if (pDelNode->pLeft == nullptr && pDelNode->pRight == nullptr)
	{
		if (pParentNode != nullptr)
		{
			if (pParentNode->pLeft == pDelNode)
			{
				pParentNode->pLeft == nullptr;
			}
			else
			{
				pParentNode->pRight == nullptr;
			}
		}
		else
		{
			pRoot = nullptr;
		}
	}
	else if (pDelNode->pLeft != nullptr && pDelNode->pRight != nullptr)
	{
		pPredecessor = nullptr;
		pSuccessor = pDelNode->pLeft;
		pStackSub->pushAVLTreeNode(pSuccessor);

		while (pSuccessor->pRight != nullptr)
		{
			pPredecessor = pSuccessor;
			pSuccessor = pSuccessor->pRight;
			pStackSub->pushAVLTreeNode(pSuccessor);
		}
		pStackMain->pushAVLTreeNode(pStackSub->popAVLTreeNode());

		if (pPredecessor != nullptr)
		{
			pPredecessor->pRight = pSuccessor->pLeft;
			pSuccessor->pLeft = pDelNode->pLeft;

			pStackSub->pushAVLTreeNode(pPredecessor->pRight);
		}
		pSuccessor->pRight = pDelNode->pRight;
	}
	
	SAFE_DELETE(pDelNode);

	balanceAVLTree(pStackSub);
	balanceAVLTree(pStackMain);

	pStackMain->deleteLinkedStack();
	pStackSub->deleteLinkedStack();
	SAFE_DELETE(pStackMain);
	SAFE_DELETE(pStackSub);

	return ret;
}

avlTreeNode* avlTreeNode::rotateLLAVLTree()
{
	avlTreeNode* pLeftNode = nullptr;

	pLeftNode = pLeft;
	pLeft = pLeftNode->pRight;
	pLeftNode->pRight = this;

	updateHeightAndBalanceAVL();
	pLeftNode->updateHeightAndBalanceAVL();

	return pLeftNode;
}

avlTreeNode* avlTreeNode::rotateRRAVLTree()
{
	avlTreeNode* pRightNode = nullptr;

	pRightNode = pRight;
	pRight = pRightNode->pLeft;
	pRightNode->pLeft = this;

	updateHeightAndBalanceAVL();
	pRightNode->updateHeightAndBalanceAVL();

	return pRightNode;
}

avlTreeNode* avlTreeNode::rotateLRAVLTree()
{
	avlTreeNode* pReturn = nullptr;
	avlTreeNode* pLeftNode = nullptr;

	pLeftNode = pLeft;
	pLeft = pLeftNode->rotateRRAVLTree();
	pReturn = rotateLLAVLTree();

	return pReturn;
}

avlTreeNode* avlTreeNode::rotateRLAVLTree()
{
	avlTreeNode* pReturn = nullptr;
	avlTreeNode* pRightNode = nullptr;

	pRightNode = pRight;
	pRight = pRightNode->rotateLLAVLTree();
	pReturn = rotateRRAVLTree();

	return pReturn;
}

void avlTreeNode::updateHeightAndBalanceAVL()
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (pLeft != nullptr)
	{
		leftHeight = pLeft->height;
	}
	if (pRight != nullptr)
	{
		rightHeight = pRight->height;
	}
	if (leftHeight > rightHeight)
	{
		height = leftHeight + 1;
	}
	else
	{
		height = rightHeight + 1;
	}

	balance = leftHeight - rightHeight;
}
