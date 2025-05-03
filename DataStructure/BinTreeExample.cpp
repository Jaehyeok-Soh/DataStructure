#include "pch.h"
#include "BinTree.h"

int BinTreeExample()
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
	//binTree.deleteBinTree();

	//bintreetravelsal
	//recursive

	std::cout << "Preorder Recursive Traversal\n";
	binTree.preorderTraversalRecursiveBinTree();

	std::cout << "Inorder Recursive Traversal\n";
	binTree.inorderTraversalRecursiveBinTree();

	std::cout << "Postorder Recursive Traversal\n";
	binTree.postorderTraversalRecursiveBinTree();

	//binTree.deleteBinTree();

	//
	bool compareResult = false;
	int count(0);
	BinTree* copyBinTree;

	std::cout << "original binaray tree\n";
	binTree.displayBinTree();

	copyBinTree = binTree.copyBinTree();
	std::cout << "copied binary tree\n";
	copyBinTree->displayBinTree();

	compareResult = binTree.equalBinTree(copyBinTree);
	std::cout << "compare result : " << compareResult << std::endl;

	count = binTree.getNodeCountBT();
	std::cout << "binary tree node count : " << count << std::endl;

	count = binTree.getLeafNodeCountBT();
	std::cout << "terminal node count : " << count << std::endl;

	count = binTree.getHeightBT();
	std::cout << "binary tree height : " << count << std::endl;

	binTree.deleteBinTree();
	//copyBinTree->deleteBinTree();
	SAFE_DELETE(copyBinTree);

	return 0;
}