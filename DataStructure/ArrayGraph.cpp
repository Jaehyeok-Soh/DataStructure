#include "pch.h"
#include "ArrayGraph.h"

ArrayGraph::ArrayGraph(int _maxVertexCount, int _graphType)
{
	maxVertexCount = _maxVertexCount;
	graphType = _graphType;
	
	ppAdjEdge = new int*[_maxVertexCount]();
	for (auto i = 0; i < _maxVertexCount; i++)
	{
		ppAdjEdge[i] = new int[_maxVertexCount]();
	}
	
	pVertex = new int[maxVertexCount]();
}

void ArrayGraph::deleteArrayGraph()
{
	for (auto i = 0; i < maxVertexCount; i++)
	{
		SAFE_DELETE_ARRAY(ppAdjEdge[i]);
	}
	SAFE_DELETE_ARRAY(ppAdjEdge);
	SAFE_DELETE_ARRAY(pVertex);
}

bool ArrayGraph::isEmptyAG()
{
	return false;
}

bool ArrayGraph::addVertexAG(int vertexID)
{
	int ret = SUCCESS;

	if (vertexID < this->maxVertexCount)
	{
		if (this->pVertex[vertexID] == NOT_USED)
		{
			this->pVertex[vertexID] = USED;
			this->currentVertextCount++;
		}
		else
		{
			std::cout << "error, conflict node\n";
			ret = FAIL;
		}
	}
	else
	{
		std::cout << "error, node is full\n";
		ret = FAIL;
	}

	return false;
}

bool ArrayGraph::addEdgeAG(int fromVertexID, int toVertexID)
{
	return addEdgewithWeightAG(fromVertexID, toVertexID, USED);
}

bool ArrayGraph::addEdgewithWeightAG(int fromVertexID, int toVertexID, int weight)
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

	this->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (this->graphType == GRAPH_UNDIRECTED)
	{
		this->ppAdjEdge[toVertexID][fromVertexID] = weight;
	}

	return ret;
}

bool ArrayGraph::checkVertexValid(int vertexID)
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

bool ArrayGraph::removeVertexAG(int vertexID)
{
	bool ret = SUCCESS;

	if (checkVertexValid(vertexID) != SUCCESS)
	{
		ret = FAIL;
		return ret;
	}

	for (auto i = 0; i < this->maxVertexCount; i++)
	{
		removeEdgeAG(vertexID, i);
		removeEdgeAG(i, vertexID);
	}

	this->pVertex[vertexID] = NOT_USED;

	return ret;
}

bool ArrayGraph::removeEdgeAG(int fromVertexID, int toVertexID)
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

	this->ppAdjEdge[fromVertexID][toVertexID] = 0;

	if (this->graphType == GRAPH_UNDIRECTED)
	{
		this->ppAdjEdge[toVertexID][fromVertexID] = 0;
	}

	return ret;
}

void ArrayGraph::displayArrayGraph()
{
	for (auto i = 0; i < maxVertexCount; i++)
	{
		for (auto j = 0; j < maxVertexCount; j++)
		{
			std::cout << ppAdjEdge[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
