#pragma once
#include "avlLinkedStack.h"

#define VALUE_SIZE 100

class avlTreeNodeData
{
public:
	int key;
	char value[VALUE_SIZE + 1];
};

class avlTreeNode
{
public:
	avlTreeNodeData data;

	int balance = 0;
	int height = 0;
	avlTreeNode* pLeft = nullptr;
	avlTreeNode* pRight = nullptr;

	avlTreeNode* rotateLLAVLTree();
	avlTreeNode* rotateRRAVLTree();
	avlTreeNode* rotateLRAVLTree();
	avlTreeNode* rotateRLAVLTree();

	void updateHeightAndBalanceAVL();
};

class avlTree
{
public: 
	avlTreeNode* pRoot;

	bool insertNodeAVL(avlTreeNodeData element);
	void balanceAVLTree(avlLinkedStack* pStack);

	bool deleteNodeAVL(int key);
};

