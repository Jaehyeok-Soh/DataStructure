#include "pch.h"
#include "LinkedGraph.h"
#include "GraphLinkedStack.h"

void LinkedGraph::traversalDFS(int startVertexID)
{
	int vertexID = 0;
	GraphLinkedStack* pStack = new GraphLinkedStack();
	GraphLinkedStackNode* pStackNode = nullptr;
	GraphListNode* pListNode = nullptr;
	bool* pVisited = new bool[maxVertexCount]();

	pVisited[startVertexID] = true;
	pStack->pushLSForDFS(startVertexID);

	while (pStack->isLinkedStackEmpty() == false)
	{
		pStackNode = pStack->popLS();
		if (pStackNode != nullptr)
		{
			vertexID = pStackNode->vertextID;
			std::cout << vertexID << "-visited\n";

			pListNode = ppAdjEdge[vertexID].pHead;
			while (pListNode != nullptr)
			{
				int vertexID = pListNode->data.vertexID;
				if (pVisited[vertexID] == false)
				{
					pVisited[vertexID] = true;
					pStack->pushLSForDFS(vertexID);
				}

				pListNode = pListNode->pNext;
			}
		}
	}

	SAFE_DELETE_ARRAY(pVisited);
	pStack->deleteLinkedStack();
	SAFE_DELETE(pStack);
}

void LinkedGraph::traversalBSF(int startVertexID)
{
	int vertextID = 0;
	
	GraphLinkedQueue* pQueue = new GraphLinkedQueue();
	GraphLinkedQueueNode* pQueueNode = nullptr;

	GraphListNode* pListNode = nullptr;
	bool* pVisited = new bool[maxVertexCount]();

	pVisited[startVertexID] = true;

	enqueueLQForBFS(pQueue, startVertexID);

	while (pQueue->isLinkedDequeEmpty() == false)
	{
		pQueueNode = pQueue->deleteFrontLD();
		if (pQueueNode != nullptr)
		{
			vertextID = pQueueNode->vertexID;
			std::cout << vertextID << "-visited\n";

			pListNode = ppAdjEdge[vertextID].pHead;
			while (pListNode != nullptr)
			{
				int vertexId = pListNode->data.vertexID;
				if (pVisited[vertexId] == false)
				{
					pVisited[vertexId] = true;
					enqueueLQForBFS(pQueue, vertexId);
				}
				pListNode = pListNode->pNext;
			}
		}
	}

	SAFE_DELETE_ARRAY(pVisited);
	pQueue->deleteLinkedDeque();
	SAFE_DELETE(pQueue);
}