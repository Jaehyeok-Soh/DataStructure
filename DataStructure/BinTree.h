#pragma once
class BinTreeNode
{
public:
	char data;
	BinTreeNode* pLeftChild = nullptr;
	BinTreeNode* pRightChild = nullptr;

	BinTreeNode() = default;
	BinTreeNode(char _data);
	~BinTreeNode();

	BinTreeNode* insertLeftChildNodeBT(BinTreeNode element);
	BinTreeNode* insertRightChildNodeBT(BinTreeNode element);
	BinTreeNode* getLeftChildNodeBT();
	BinTreeNode* getRightChildNodeBT();
	void deleteBinTreeNode();
};

class BinTree
{
public:
	BinTreeNode* pRootNode;

	BinTree();
	BinTree(BinTreeNode rootNode);
	~BinTree();

	BinTreeNode* getRootNodeBT();
	void deleteBinTree();
};