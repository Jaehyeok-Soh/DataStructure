#include "pch.h"
#include "LinkedGraph.h"

LinkedGraph* LinkedGraph::mstKruskal()
{
	LinkedGraph* pReturn = new LinkedGraph(maxVertexCount, GRAPH_UNDIRECTED);
	int maxNodeCount = maxVertexCount;
	int currentNodeCount = currentVertexCount;
	int edgeCount = currentEdgeCount;
	bool isCycle = false;
	GraphArrayMinHeap* pMinHeap = orderEdges();
	GraphHeapNode* pHeapNode = nullptr;

	for (auto i = 0; i < edgeCount; i++)
	{
		pHeapNode = pMinHeap->deleteMinHeapAH();

		if (pHeapNode != nullptr)
		{
			isCycle = pReturn->checkCycle(pHeapNode->fromVertexID, pHeapNode->toVertexID);

			if (isCycle == false)
			{
				if (pReturn->pVertex[pHeapNode->fromVertexID] != USED)
				{
					pReturn->addVertexLG(pHeapNode->fromVertexID);
				}
				if (pReturn->pVertex[pHeapNode->toVertexID] != USED)
				{
					pReturn->addVertexLG(pHeapNode->toVertexID);
				}

				pReturn->addEdgewithWeightLG(pHeapNode->fromVertexID, pHeapNode->toVertexID, pHeapNode->key);

				std::cout << i << " : min weight "
					<< pHeapNode->fromVertexID << ", "
					<< pHeapNode->toVertexID << "->"
					<< pHeapNode->key << std::endl;

				SAFE_DELETE(pHeapNode);
				if (pReturn->currentVertexCount == currentNodeCount)
				{
					break;
				}
			}
		}
	}

	return pReturn;
}

//https://github.com/woosanguk/c-data-structure/blob/master/08/graph-mst/graphmst.c
//line 56
GraphArrayMinHeap* LinkedGraph::orderEdges()
{
	GraphArrayMinHeap* pReturn = new GraphArrayMinHeap(currentEdgeCount);

	GraphListNode* pListNode = nullptr;
	GraphLinkedList pEdgeList;
	for (auto i = 0; i < maxVertexCount; i++) {
		if (checkVertexValid(i) == true) {
			pEdgeList = ppAdjEdge[i];
			pListNode = pEdgeList.pHead;
			while (pListNode != nullptr) {
				int vertexID = pListNode->data.vertexID;
				int weight = pListNode->data.weight;
				if (graphType == GRAPH_DIRECTED || (graphType == GRAPH_UNDIRECTED && i < vertexID)) {
					GraphHeapNode heapNode;
					heapNode.fromVertexID = i;
					heapNode.toVertexID = vertexID;
					heapNode.key = weight;
					pReturn->insertMinHeapAH(heapNode);
				}
				pListNode = pListNode->pNext;
			}
		}
	}

	return pReturn;
}

//line 93
bool LinkedGraph::checkCycle(int fromVertexID, int toVertexID)
{
	int ret = false;

	int vertextID = 0;
	GraphLinkedStack* pStack;
	GraphLinkedStackNode* pStackNode = nullptr;
	GraphListNode* pListNode = nullptr;
	bool* pVisited = new bool[maxVertexCount]();

	pVisited[fromVertexID] = true;
	pStack->pushLSForDFS(fromVertexID);

	while (pStack->isLinkedStackEmpty() == false) {
		pStackNode = pStack->popLS();
		if (pStackNode != nullptr) {
			vertextID = pStackNode->vertextID;
			if (vertextID == toVertexID) {
				std::cout << fromVertexID << ", " << toVertexID << std::endl;
				ret = true;
				break;
			}

			pListNode = ppAdjEdge[vertextID].pHead;
			while (pListNode != NULL) {
				int vertexID = pListNode->data.vertexID;
				if (pVisited[vertexID] == false) {
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
	return ret;
}