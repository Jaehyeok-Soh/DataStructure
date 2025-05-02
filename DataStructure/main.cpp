#include "pch.h"
#include "BinTree.h"

int main()
{
	BinTree binTree = BinTree(BinTreeNode('A'));
	auto nodeB = binTree.getRootNodeBT()->insertLeftChildNodeBT(BinTreeNode('B'));
	auto nodeC = nodeB->insertRightChildNodeBT(BinTreeNode('C'));
	BinTreeNode* nodeD, * nodeE, * nodeF;
	if (nodeB)
	{
		nodeD = nodeB->insertLeftChildNodeBT(BinTreeNode('D'));
	}
	if (nodeC)
	{
		nodeE = nodeC->insertLeftChildNodeBT(BinTreeNode('E'));
		nodeF = nodeC->insertRightChildNodeBT(BinTreeNode('F'));
	}
	binTree.deleteBinTree();

	return 0;
}