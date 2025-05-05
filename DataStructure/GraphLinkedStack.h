#pragma once
class GraphLinkedStackNode
{
public:
	int vertextID = 0;
	GraphLinkedStackNode* next = nullptr;

	GraphLinkedStackNode();
	~GraphLinkedStackNode();
};

class GraphLinkedStack
{
public:
	int currentElementCount = 0;
	GraphLinkedStackNode* pTopElement = nullptr;

	GraphLinkedStack();
	~GraphLinkedStack();

	bool pushLS(GraphLinkedStackNode element);
	GraphLinkedStackNode* popLS();
	GraphLinkedStackNode* peekLS();
	void deleteLinkedStack();
	bool isLinkedStackFull();
	bool isLinkedStackEmpty();
	void displayLinkedStack();

	//LinkedGraph
	//DFS
	bool pushLSForDFS(int nodeID)
	{
		GraphLinkedStackNode node;
		node.vertextID = nodeID;
		return pushLS(node);
	}
};