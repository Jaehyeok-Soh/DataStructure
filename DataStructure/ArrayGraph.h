#pragma once
#include "Define.h"

class ArrayGraph
{
public:
	//max vertex(node)
	int maxVertexCount = 0;
	int currentVertextCount = 0;

	//1-Undirected 2-Directed
	int graphType = GRAPH_UNDIRECTED;

	//Edge, 2D array
	int** ppAdjEdge;

	//vertex, 1D array
	int* pVertex;

	ArrayGraph() = default;
	ArrayGraph(int _maxVertexCount, int _graphType);
	void deleteArrayGraph();

	bool isEmptyAG();

	bool addVertexAG(int vertexID);
	bool addEdgeAG(int fromVertexID, int toVertexID);
	bool addEdgewithWeightAG(int fromVertexID, int toVertexID, int weight);

	bool checkVertexValid(int vertexID);

	bool removeVertexAG(int vertexID);

	bool removeEdgeAG(int fromVertexID, int toVertexID);
	void displayArrayGraph();
};