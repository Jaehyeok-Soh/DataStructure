#pragma once
#include "avlTree.h"

struct avlStackNode
{
	avlTreeNode* data = nullptr;
	avlStackNode* pNext = nullptr;
};

class avlLinkedStack
{
public:
	int currentElementCount = 0;
	avlStackNode* pTop = nullptr;;

	bool pushLS(avlStackNode element);
	avlStackNode* popLS();
	avlStackNode* peekLS();
	void deleteLinkedStack();
	bool isLinkedStackFull();
	bool isLinkedStackEmpty();

	avlTreeNode* popAVLTreeNode();
	bool pushAVLTreeNode(avlTreeNode* data);
	avlTreeNode* peekAVLTreeNode();
};

