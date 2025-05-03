#include "pch.h"
#include "BinTree.h"

BinTreeNode* BinTreeNode::copyBinTreeNode()
{
	BinTreeNode* pReturn = nullptr;

	pReturn - new BinTreeNode();

	pReturn = this;
	if(pLeftChild) pReturn->pLeftChild = pLeftChild->copyBinTreeNode();
	if(pRightChild) pReturn->pRightChild = pRightChild->copyBinTreeNode();

	return pReturn;
}

bool BinTreeNode::equalBinTreeNode(BinTreeNode* pSecond)
{
	bool ret = false;

	if (data == pSecond->data 
		&& (pLeftChild && pLeftChild->equalBinTreeNode(pSecond->pLeftChild)) 
		&& (pRightChild && pRightChild->equalBinTreeNode(pSecond->pRightChild)))
	{
		ret = true;
	}

	return ret;
}

int BinTreeNode::getNodeCountBTNode()
{
	int ret = 0;

	if (pLeftChild)
	{
		ret = pLeftChild->getNodeCountBTNode() + 1;
	}

	if (pRightChild)
	{
		ret = pRightChild->getNodeCountBTNode() + 1;
	}

	//ret = pLeftChild->getNodeCountBTNode() 
	//	+ pRightChild->getNodeCountBTNode() 
	//	+ 1;

	return 0;
}

int BinTreeNode::getLeafNodeCountBTNode()
{
	int ret = 0;

	if (pLeftChild == nullptr && pRightChild == nullptr)
	{
		ret = 1;
	}
	else
	{
		if (pLeftChild)
		{
			ret = pLeftChild->getLeafNodeCountBTNode() + 1;
		}

		if (pRightChild)
		{
			ret = pRightChild->getLeafNodeCountBTNode() + 1;
		}
		
		//ret = pLeftChild->getLeafNodeCountBTNode() + pRightChild->getLeafNodeCountBTNode();
	}

	return ret;
}

int BinTreeNode::getHeightBTNode()
{
	int ret = 0;

	if (pLeftChild == nullptr && pRightChild == nullptr)
	{
		ret = 1;
	}
	else
	{
		int leftChildHeight(0);
		int rightChildHeight(0);

		if (pLeftChild)
		{
			leftChildHeight = pLeftChild->getHeightBTNode();
		}

		if (pRightChild)
		{
			rightChildHeight = pRightChild->getHeightBTNode();
		}

		if (leftChildHeight >= rightChildHeight)
		{
			ret = leftChildHeight + 1;
		}
		else
		{
			ret = rightChildHeight + 1;
		}
	}

	return ret;
}

void BinTreeNode::displayBinTreeNode(int level, char type)
{
	for (auto i = 0; i < level; i++)
	{
		std::cout << "    ";
	}

	std::cout << "=" << level << ", " << type << "=>" << data << std::endl;

	if(pLeftChild) pLeftChild->displayBinTreeNode(level + 1, 'L');
	if(pRightChild) pRightChild->displayBinTreeNode(level + 1, 'R');
}

BinTree* BinTree::copyBinTree()
{
	BinTree* pReturn = nullptr;

	if (pRootNode != nullptr)
	{
		pReturn = new BinTree();
		pReturn->pRootNode = pRootNode->copyBinTreeNode();
	}
	else
	{
		std::cout << "error, empty tree";
	}

	return pReturn;
}

bool BinTree::equalBinTree(BinTree* pSecond)
{
	bool ret = false;

	if (pSecond == nullptr)
	{
		return ret;
	}
	else if (pRootNode->equalBinTreeNode(pSecond->pRootNode) == true)
	{
		ret = true;
	}

	return ret;
}

int BinTree::getNodeCountBT()
{
	int ret = 0;

	ret = pRootNode->getNodeCountBTNode();

	return ret;
}

int BinTree::getLeafNodeCountBT()
{
	int ret = 0;

	ret = pRootNode->getLeafNodeCountBTNode();

	return ret;
}

int BinTree::getHeightBT()
{
	int ret = 0;

	ret = pRootNode->getHeightBTNode();

	return ret;
}

void BinTree::displayBinTree()
{
	pRootNode->displayBinTreeNode(0, 'O');
}
