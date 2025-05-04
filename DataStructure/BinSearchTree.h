#pragma once

class BinSearchTreeNode
{
public:
	int key = 0;
	char value = '\0';

	BinSearchTreeNode* pLeft = nullptr;
	BinSearchTreeNode* pRight = nullptr;

	BinSearchTreeNode* SearchInternalRecursiveBST(int key);
	void deleteBinSearchTreeInternal();
};

class BinSearchTree
{
public:
	BinSearchTreeNode* pRoot = nullptr;

	bool insertElementBST(BinSearchTreeNode element);
	bool deleteElementBST(int key);
	BinSearchTreeNode* searchRecursiveBST(int key);
	BinSearchTreeNode* searchBST(int key);
	void deleteBinSearchTree();
};