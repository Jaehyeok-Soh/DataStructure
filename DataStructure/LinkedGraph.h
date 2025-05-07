#pragma once
#include "ArrayGraph.h"
#include "GraphLinkedList.h"
#include "GraphLinkedQueue.h"
#include "GraphArrayHeap.h"
#include "GraphLinkedStack.h"

struct GraphEdge
{
	int vertexIDFrom;
	int vertexIDTo;
	int weight;
};

class LinkedGraph
{
public:
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
	void deleteGraphNode(GraphLinkedList* pList, int delVertxID);
	int findGraphNodePosition(GraphLinkedList* pList, int vertexID);
	void displayLinkedGraph();
	
	bool addLLElementForVertex(GraphLinkedList& pList, int position, GraphVertex vertex);

	bool enqueueLQForBFS(GraphLinkedQueue* pQueue, int nodeID);

	//traversal
	//graphLinkedStack.h
	void traversalDFS(int startVertexID);
	void traversalBSF(int startVertexID);

	//graphMST
	LinkedGraph* mstKruskal();
	LinkedGraph* mstPrim(int startVertexID);
	void getMinWeightEdge(LinkedGraph* pMST, int fromVertexID, GraphEdge* pMinWeightEdge);

	GraphArrayMinHeap* orderEdges();
	bool checkCycle(int fromVertexID, int toVertexID);
	bool checkEdge(int fromVertexID, int toVertexID);

	//shortest path
	int* shortestPathDijkstra(int startVertexID);
	int getMinDistance(int* distance, bool* isSelected, int maxNodeCount);
	int getEdgeWeight(int fromVertexID, int toVertexID);
};