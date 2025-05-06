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

LinkedGraph* LinkedGraph::mstPrim(int startVertexID)
{
	int nodeCount = currentVertexCount;
	int fromVertexID = 0;
	GraphEdge minWeightEdge = { 0, };
	LinkedGraph* pReturn = new LinkedGraph(maxVertexCount, GRAPH_UNDIRECTED);

	pReturn->addVertexLG(startVertexID);
	while (pReturn->currentVertexCount < nodeCount)
	{
		minWeightEdge.vertexIDFrom = 0;
		minWeightEdge.vertexIDTo = 0;
		minWeightEdge.weight = 99999;//define max_int

		for (auto i = 0; i < maxVertexCount; i++)
		{
			if (pReturn->pVertex[i] == true)
			{
				fromVertexID = i;
				getMinWeightEdge(pReturn, fromVertexID, &minWeightEdge);
			}
		}
		std::cout << pReturn->currentVertexCount << ">> min weight : "
			<< minWeightEdge.vertexIDFrom << ", "
			<< minWeightEdge.vertexIDTo << " -> "
			<< minWeightEdge.weight << std::endl;

		pReturn->addVertexLG(minWeightEdge.vertexIDTo);
		pReturn->addEdgewithWeightLG(minWeightEdge.vertexIDFrom, minWeightEdge.vertexIDTo, minWeightEdge.weight);
	}

	return pReturn;
}

void LinkedGraph::getMinWeightEdge(LinkedGraph* pMST, int fromVertexID, GraphEdge* pMinWeightEdge)
{
	bool isCycle = false;
	bool isAlready = false;
	GraphLinkedList pEdgeList = ppAdjEdge[fromVertexID];
	GraphListNode* pListNode = pEdgeList.pHead;

	while (pListNode != nullptr)
	{
		int vertexID = pListNode->data.vertexID;
		int weight = pListNode->data.weight;

		if (pListNode->data.weight < pMinWeightEdge->weight)
		{
			isAlready = pMST->checkEdge(fromVertexID, vertexID);
			if (isAlready == false)
			{
				isCycle = pMST->checkCycle(fromVertexID, vertexID);
			}

			if (isAlready == false && isCycle == false)
			{
				pMinWeightEdge->vertexIDFrom = fromVertexID;
				pMinWeightEdge->vertexIDTo = vertexID;
				pMinWeightEdge->weight = weight;
			}
		}

		pListNode = pListNode->pNext;
	}
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
	GraphLinkedStack* pStack = new GraphLinkedStack();
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

bool LinkedGraph::checkEdge(int fromVertexID, int toVertexID)
{
	bool ret = false;

	GraphLinkedList pEdgeList = ppAdjEdge[fromVertexID];
	int position = findGraphNodePosition(&pEdgeList, toVertexID);
	if (position >= 0)
	{
		ret = true;
	}
	return ret;
}
