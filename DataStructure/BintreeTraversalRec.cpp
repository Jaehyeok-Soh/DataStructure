#include "pch.h"
#include "BinTree.h"

void BinTreeNode::preorderTraversalRecursiveBinTreeNode()
{
	std::cout << data << " ";
	if (pLeftChild) pLeftChild->preorderTraversalRecursiveBinTreeNode();
	if (pRightChild) pRightChild->preorderTraversalRecursiveBinTreeNode();
}

void BinTreeNode::postorderTraversalRecursiveBinTreeNode()
{
	if (pLeftChild) pLeftChild->postorderTraversalRecursiveBinTreeNode();
	if (pRightChild) pRightChild->postorderTraversalRecursiveBinTreeNode();
	std::cout << data << " ";
}

void BinTreeNode::inorderTraversalRecursivBinTreeNode()
{
	if (pLeftChild) pLeftChild->inorderTraversalRecursivBinTreeNode();
	std::cout << data << " ";
	if (pRightChild) pRightChild->inorderTraversalRecursivBinTreeNode();
}

void BinTree::preorderTraversalRecursiveBinTree()
{
	if (pRootNode)
	{
		pRootNode->preorderTraversalRecursiveBinTreeNode();
	}
}

void BinTree::inorderTraversalRecursiveBinTree()
{
	if (pRootNode)
	{
		pRootNode->inorderTraversalRecursivBinTreeNode();
	}
}

void BinTree::postorderTraversalRecursiveBinTree()
{
	if (pRootNode)
	{
		pRootNode->postorderTraversalRecursiveBinTreeNode();
	}
}

