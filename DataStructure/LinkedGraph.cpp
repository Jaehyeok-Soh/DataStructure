#include "pch.h"
#include "LinkedGraph.h"

LinkedGraph::LinkedGraph(int _maxVertexCount, int _graphType)
{
	currentEdgeCount = 0;
	currentVertexCount = 0;
	maxVertexCount = _maxVertexCount;
	graphType = _graphType;
	ppAdjEdge = new GraphLinkedList[_maxVertexCount]();
	pVertex = new int[_maxVertexCount]();
}

LinkedGraph::~LinkedGraph()
{
	if (ppAdjEdge != nullptr)
	{
		deleteLinkedGraph();
		SAFE_DELETE_ARRAY(pVertex);
	}
}

void LinkedGraph::deleteLinkedGraph()
{
	for (auto i = 0; i < maxVertexCount; i++)
	{
		auto currentNode = ppAdjEdge[i].pHead;
		while (currentNode != nullptr)
		{
			auto tempNode = currentNode;
			currentNode = currentNode->pNext;
			SAFE_DELETE(tempNode);
		}
	}

	SAFE_DELETE_ARRAY(ppAdjEdge);
	SAFE_DELETE_ARRAY(pVertex);
}

bool LinkedGraph::isEmptyLG()
{
	return false;
}

bool LinkedGraph::addVertexLG(int vertexID)
{
	bool ret = SUCCESS;
	if (vertexID < this->maxVertexCount)
	{
		if (this->pVertex[vertexID] == NOT_USED)
		{
			this->pVertex[vertexID] = USED;
			this->currentVertexCount++;
		}
		else
		{
			std::cout << "error, node duplicated\n";
			ret = FAIL;
		}
	}

	return ret;
}

bool LinkedGraph::addEdgeLG(int fromVertexID, int toVertexID)
{
	return addEdgewithWeightLG(fromVertexID, toVertexID, USED);
}

bool LinkedGraph::addEdgewithWeightLG(int fromVertexID, int toVertexID, int weight)
{
	int ret = SUCCESS;
	GraphVertex toNode = GraphVertex();
	if (checkVertexValid(fromVertexID) != SUCCESS)
	{
		ret = FAIL;
		return ret;
	}
	if (checkVertexValid(toVertexID) != SUCCESS)
	{
		ret = FAIL;
		return ret;
	}

	toNode.vertexID = toVertexID;
	toNode.weight = weight;
	addLLElementForVertex(ppAdjEdge[fromVertexID], 0, toNode);
	currentEdgeCount++;

	//undirected
	if (graphType == GRAPH_UNDIRECTED)
	{
		GraphVertex fromNode;
		fromNode.vertexID = fromVertexID;
		fromNode.weight = weight;
		addLLElementForVertex(ppAdjEdge[toVertexID], 0, fromNode);
		currentEdgeCount++;
	}

	return ret;
}

bool LinkedGraph::addLLElementForVertex(GraphLinkedList& pList, int position, GraphVertex vertex)
{
	GraphListNode node = GraphListNode();

	node.data = vertex;

	return pList.addLLElment(position, node);
}

bool LinkedGraph::enqueueLQForBFS(GraphLinkedQueue* pQueue, int nodeID)
{
	GraphLinkedQueueNode node;
	node.vertexID = nodeID;
	return pQueue->insertRearLD(node);
}

bool LinkedGraph::checkVertexValid(int vertexID)
{
	bool ret = SUCCESS;

	if (vertexID >= this->maxVertexCount
		|| this->pVertex[vertexID] == NOT_USED)
	{
		std::cout << "error, not vaild node\n";
		ret = FAIL;
	}

	return ret;
}

bool LinkedGraph::removeVertexLG(int vertexID)
{
	bool ret = SUCCESS;

	if (checkVertexValid(vertexID) != SUCCESS)
	{
		ret = FAIL;
		return ret;
	}
	for (auto i = 0; i < maxVertexCount; i++)
	{
		removeEdgeLG(vertexID, i);
		removeEdgeLG(i, vertexID);
	}
	this->pVertex[vertexID] = NOT_USED;

	return ret;
}

bool LinkedGraph::removeEdgeLG(int fromVertexID, int toVertexID)
{
	bool ret = SUCCESS;

	if (checkVertexValid(fromVertexID) != SUCCESS)
	{
		ret = FAIL;
		return ret;
	}

	if (checkVertexValid(toVertexID) != SUCCESS)
	{
		ret = FAIL;
		return ret;
	}

	deleteGraphNode(&this->ppAdjEdge[fromVertexID], toVertexID);

	//undirected
	if (graphType == GRAPH_UNDIRECTED)
	{
		deleteGraphNode(&this->ppAdjEdge[toVertexID], fromVertexID);
	}

	return ret;
}

void LinkedGraph::deleteGraphNode(GraphLinkedList* pList, int delVertxID)
{
	int position = 0;
	GraphListNode* pNode = nullptr;

	position = findGraphNodePosition(pList, delVertxID);
	if (position >= 0)
	{
		pList->removeLLElement(position);
	}
}

int LinkedGraph::findGraphNodePosition(GraphLinkedList* pList, int vertexID)
{
	int position = 0;
	GraphListNode* pNode = nullptr;

	pNode = pList->pHead;
	while (pNode != nullptr)
	{
		if (pNode->data.vertexID == vertexID)
		{
			return position;
		}
		pNode = pNode->pNext;
		position++;
	}

	return -1;
}

void LinkedGraph::displayLinkedGraph()
{
	std::cout << "max node count : " << maxVertexCount << std::endl;
	std::cout << "current node count : " << currentVertexCount << std::endl;
	std::cout << "current edge count : " << currentEdgeCount << std::endl;

	GraphListNode* currentNode = nullptr;
	for (auto i = 0; i < maxVertexCount; i++)
	{
		currentNode = ppAdjEdge[i].pHead;
		std::cout << i << " : ";
		if (pVertex[i] == NOT_USED)
		{
			continue;
		}

		for (auto j = 0; j < maxVertexCount; j++)
		{
			std::cout << currentNode->data.vertexID << ", ";
			currentNode = currentNode->pNext;
			if (currentNode == nullptr)
			{
				break;
			}
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	int position = 0;
	for (auto i = 0; i < maxVertexCount; i++) {
		for (auto j = 0; j < maxVertexCount; j++) {
			position = findGraphNodePosition(&ppAdjEdge[i], j);

			if (position >= 0) {
				currentNode = ppAdjEdge[i].getLLElement(position);
				std::cout << currentNode->data.weight << " ";
			}
			else {
				std::cout << "0 ";
			}
		}
		std::cout << std::endl;
	}
}

