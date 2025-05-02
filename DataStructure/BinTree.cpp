#include "pch.h"
#include "BinTree.h"

BinTreeNode::BinTreeNode(char _data)
{
	data = _data;
}

BinTreeNode::~BinTreeNode()
{
	deleteBinTreeNode();
}

BinTreeNode* BinTreeNode::insertLeftChildNodeBT(BinTreeNode element)
{
	BinTreeNode* pReturn = nullptr;

	if (pLeftChild == nullptr)
	{
		pLeftChild = new BinTreeNode(element);
		pReturn = pLeftChild;
	}
	else
	{
		std::cout << "error, node is full\n";
	}

	return pReturn;
}

BinTreeNode* BinTreeNode::insertRightChildNodeBT(BinTreeNode element)
{
	BinTreeNode* pReturn = nullptr;

	if (pRightChild == nullptr)
	{
		pRightChild = new BinTreeNode(element);
		pReturn = pRightChild;
	}
	else
	{
		std::cout << "error, node is full\n";
	}

	return pReturn;
}

BinTreeNode* BinTreeNode::getLeftChildNodeBT()
{
	BinTreeNode* pReturn = nullptr;

	if (pLeftChild)
	{
		pReturn = pLeftChild;
	}

	return pReturn;
}

BinTreeNode* BinTreeNode::getRightChildNodeBT()
{
	BinTreeNode* pReturn = nullptr;

	if (pRightChild)
	{
		pReturn = pRightChild;
	}

	return pReturn;
}

void BinTreeNode::deleteBinTreeNode()
{
	SAFE_DELETE(pLeftChild);
	SAFE_DELETE(pRightChild);
}

BinTree::BinTree()
{
	pRootNode = nullptr;
}

BinTree::BinTree(BinTreeNode rootNode)
{
	pRootNode = new BinTreeNode(rootNode);
}

BinTree::~BinTree()
{
}

BinTreeNode* BinTree::getRootNodeBT()
{
	BinTreeNode* pReturn = nullptr;

	if (pRootNode)
	{
		pReturn = pRootNode;
	}

	return pReturn;
}

void BinTree::deleteBinTree()
{
	SAFE_DELETE(pRootNode);
}
