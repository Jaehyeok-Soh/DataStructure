#pragma once
#include "ArrayGraph.h"
#include "GraphLinkedList.h"

class LinkedGraph
{
	int maxVertexCount;
	int currentVertexCount = 0;
	int currentEdgeCount = 0;
	int graphType;
	GraphLinkedList* ppAdjEdge;
	int* pVertex;

	LinkedGraph() = default;
	LinkedGraph(int _maxVertexCount, int _graphType);
	~LinkedGraph();

	void deleteLinkedGraph();
	bool isEmptyLG();
	bool addVertexLG(int vertexID);
	bool addEdgeLG(int fromVertexID, int toVertexID);
	bool addEdgewithWeightLG(int fromVertexID, int toVertexID, int weight);
	bool checkVertexValid(int vertexID);
	bool removeVertexLG(int vertexID);
	bool removeEdgeLG(int fromVertexID, int toVertexID);
	void deleteGraphNode(GraphLinkedList& pList, int delVertxID);
	int findGraphNodePosition(GraphLinkedList& pList, int vertexID);
	void displayLinkedGraph();
	bool addLLElementForVertex(GraphLinkedList& pList, int position, GraphVertex vertex);
};