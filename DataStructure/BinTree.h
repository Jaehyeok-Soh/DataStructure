#pragma once

class BinTreeNode
{
public:
	char data;
	bool visited = false;
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

	//bintreetraversal
	//recursive func
	void preorderTraversalRecursiveBinTreeNode();
	void inorderTraversalRecursivBinTreeNode();
	void postorderTraversalRecursiveBinTreeNode();

	//op
	BinTreeNode* copyBinTreeNode();
	bool equalBinTreeNode(BinTreeNode* pSecond);
	int getNodeCountBTNode();
	int getLeafNodeCountBTNode();
	int getHeightBTNode();
	void displayBinTreeNode(int level, char type);
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

	//traversal
	//v, l, r
	//preorder traversal v-l-r
	//inorder traversal l-v-r
	//postorder traversal l-r-v

	//bintreetraversal
	//recursive func
	void preorderTraversalRecursiveBinTree();
	void inorderTraversalRecursiveBinTree();
	void postorderTraversalRecursiveBinTree();

	//iterate
	void preorderTraversalBinTree();
	void inorderTraversalBintree();
	void postorderTraversalBintree();
	void levelOrderTraversalBintree();

	//operation
	BinTree* copyBinTree();
	bool equalBinTree(BinTree* pSecond);
	int getNodeCountBT();
	int getLeafNodeCountBT();
	int getHeightBT();
	void displayBinTree();
};