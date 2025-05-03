#pragma once
#include "BinTree.h"

class BintreeLinkedStackNode
{
public:
	BinTreeNode* data = nullptr;
	BintreeLinkedStackNode* next = nullptr;

	BintreeLinkedStackNode() = default;
	BintreeLinkedStackNode(BinTreeNode _data);

	bool pushLSBinTreeNode(BinTreeNode* _data);
};

class BintreeLinkedStack
{
public:
	int currentElementCount = 0;
	BintreeLinkedStackNode* pTop = nullptr;

	~BintreeLinkedStack();

	bool pushLS(BinTreeNode* element);
	BintreeLinkedStackNode* popLS();

	void deleteLinkedStack();
};