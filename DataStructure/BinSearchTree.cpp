#include "pch.h"
#include "BinSearchTree.h"

BinSearchTreeNode* BinSearchTreeNode::SearchInternalRecursiveBST(int key)
{
	return nullptr;
}

void BinSearchTreeNode::deleteBinSearchTreeInternal()
{
	if (this != nullptr)
	{
		pLeft->deleteBinSearchTreeInternal();
		pRight->deleteBinSearchTreeInternal();
	}
}

bool BinSearchTree::insertElementBST(BinSearchTreeNode element)
{
	bool ret(false);

	BinSearchTreeNode* pParentNode(nullptr), *pNewNode(nullptr);
	
	pParentNode = pRoot;
	while (pParentNode != nullptr)
	{
		if (element.key == pParentNode->key)
		{
			std::cout << "error, key conflict\n";
			ret = false;
			return ret;
		}
		else if(element.key < pParentNode->key)
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

	pNewNode = new BinSearchTreeNode();
	*pNewNode = element;
	if (pParentNode == nullptr)
	{
		pRoot = pNewNode;
	}
	else
	{
		if (pNewNode->key < pParentNode->key)
		{
			pParentNode->pLeft = pNewNode;
		}
		else
		{
			pParentNode->pRight = pNewNode;
		}
	}

	ret = true;

	return ret;
}

bool BinSearchTree::deleteElementBST(int key)
{
	bool ret = true;
	BinSearchTreeNode* pDelNode(nullptr), * pParentNode(nullptr);
	BinSearchTreeNode* pPredecessor(nullptr), * pSuccessor(nullptr);
	BinSearchTreeNode* pChildNode(nullptr);

	pDelNode = pRoot;

	while (pDelNode != nullptr)
	{
		if (key == pDelNode->key)
		{
			break;
		}

		//delNode == root >> parentNode == nullptr
		pParentNode = pDelNode;
		if (key < pDelNode->key)
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

	//none child node
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
				pParentNode->pRight = nullptr;
			}
		}
		else
		{
			//delNode = root
			pRoot = nullptr;
		}
	}
	else if (pDelNode->pLeft != nullptr && pDelNode->pRight != nullptr)
	{
		//find largest key from left subtree
		pPredecessor = pDelNode;
		pSuccessor = pDelNode->pLeft;
		while (pSuccessor->pRight != nullptr)
		{
			pPredecessor = pSuccessor;
			pSuccessor = pSuccessor->pRight;
		}

		//swap delNode to largest key from left subtree
		pPredecessor->pRight = pSuccessor->pLeft;//only have left child or nullptr
		pSuccessor->pLeft = pDelNode->pLeft;
		pSuccessor->pRight = pDelNode->pRight;

		if (pParentNode != nullptr)
		{
			if (pParentNode->pLeft == pDelNode)
			{
				pParentNode->pLeft = pSuccessor;
			}
			else
			{
				pParentNode->pRight = pSuccessor;
			}
		}
		else
		{
			pRoot = pSuccessor;
		}
	}
	else
	{
		//delNode have one child
		if (pDelNode->pLeft != nullptr)
		{
			pChildNode = pDelNode->pLeft;
		}
		else
		{
			pChildNode = pDelNode->pRight;
		}

		if (pParentNode != nullptr)
		{
			if (pParentNode->pLeft == pDelNode)
			{
				pParentNode->pLeft = pChildNode;
			}
			else
			{
				pParentNode->pRight = pChildNode;
			}
		}
		else
		{
			pRoot = pChildNode;
		}
	}

	SAFE_DELETE(pDelNode);

	return ret;
}

BinSearchTreeNode* BinSearchTree::searchRecursiveBST(int key)
{
	//TODO 20250504
	return nullptr;
}

BinSearchTreeNode* BinSearchTree::searchBST(int key)
{
	BinSearchTreeNode* pReturn = nullptr;

	pReturn = pRoot;
	while (pReturn != nullptr)
	{
		if (key == pReturn->key)
		{
			break;
		}
		else if (key < pReturn->key)
		{
			pReturn = pReturn->pLeft;
		}
		else
		{
			pReturn = pReturn->pRight;
		}
	}

	return pReturn;
}

void BinSearchTree::deleteBinSearchTree()
{
	pRoot->deleteBinSearchTreeInternal();
	SAFE_DELETE(pRoot);
}
