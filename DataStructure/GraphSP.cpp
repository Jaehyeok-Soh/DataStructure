#include "pch.h"
#include "LinkedGraph.h"

int* LinkedGraph::shortestPathDijkstra(int startVertexID)
{
	int* pReturn = new int[maxVertexCount]();//distance(weight)
	bool* pSelected = new bool[maxVertexCount]();
	int nodeCount(currentVertexCount), maxNodeCount(maxVertexCount);
	int weight = 0;
	int vertexID = 0, y_w = 0, y_v = 0;
	GraphListNode* pListNode = nullptr;
	GraphLinkedList pEdgeList;

	for (auto i = 0; i < maxVertexCount; i++)
	{
		if (i == startVertexID)
		{
			pReturn[i] = 0;
		}
		else
		{
			if (pVertex[i] == USED)
			{
				pSelected[i] = true;
				pReturn[i] = getEdgeWeight(startVertexID, i);
			}
			else
			{
				pSelected[i] = false;
				pReturn[i] = MAX_INT;
			}
		}
	}

	for (auto i = 0; i < maxVertexCount; i++)
	{
		std::cout << startVertexID << ", " << i << " -> " << pReturn[i] << std::endl;
	}

	for (auto i = 0; i < currentVertexCount - 1; i++)
	{
		std::cout << i + 1 << "-iteration\n";
		vertexID = getMinDistance(pReturn, pSelected, maxVertexCount);
		pSelected[vertexID] = false;

		pEdgeList = ppAdjEdge[vertexID];

		pListNode = pEdgeList.pHead;
		while (pListNode != nullptr)
		{
			int toVertexID = pListNode->data.vertexID;
			int weight = pListNode->data.weight;

			y_v = pReturn[vertexID];
			y_w = pReturn[toVertexID];
			if (y_v + weight < y_w)
			{
				pReturn[toVertexID] = y_v + weight;
			}
			pListNode = pListNode->pNext;
		}

		for (auto j = 0; j < maxVertexCount; j++)
		{
			std::cout << "\t" << startVertexID << ", " << j << " -> " << pReturn[j] << std::endl;
		}
	}

	SAFE_DELETE_ARRAY(pSelected);

	return pReturn;;
}

int LinkedGraph::getMinDistance(int* distance, bool* isSelected, int maxNodeCount)
{
	int ret = 0;
	int min_distance = MAX_INT;

	for (auto i = 0; i < maxVertexCount; i++)
	{
		if (isSelected[i] == true && distance[i] < min_distance)
		{
			min_distance = distance[i];
			ret = i;
		}
	}

	return ret;
}

int LinkedGraph::getEdgeWeight(int fromVertexID, int toVertexID)
{
	int ret = MAX_INT;
	int position = 0;
	GraphLinkedList edgeList;
	GraphListNode* pListNode = nullptr;
	edgeList = ppAdjEdge[fromVertexID];
	if (edgeList.pHead != nullptr)
	{
		position = findGraphNodePosition(&edgeList, toVertexID);
		if (position >= 0)
		{
			pListNode = edgeList.getLLElement(position);
			if (pListNode != nullptr)
			{
				ret = pListNode->data.weight;
			}
		}
	}

	return ret;
}

int** LinkedGraph::shortestPathFloyd()
{
	int** pReturn = nullptr;
	int weight = 0;
	int maxNodeCount(maxVertexCount);

	pReturn = new int* [maxVertexCount]();
	for (auto i = 0; i < maxVertexCount; i++)
	{
		pReturn[i] = new int[maxVertexCount]();
	}

	for (auto i = 0; i < maxVertexCount; i++)
	{
		for (auto j = 0; j < maxVertexCount; j++)
		{
			if (i == j)
			{
				pReturn[i][j] = 0;
			}
			else
			{
				pReturn[i][j] = getEdgeWeight(i, j);
			}
		}
	}

	printMatrix(pReturn, maxVertexCount);

	for (auto v = 0; v < maxVertexCount; v++)//via
	{
		for (auto r = 0; r < maxVertexCount; r++)//source
		{
			for (auto s = 0; s < maxVertexCount; s++)//dest
			{
				//r->s > r->v + v->s
				if (pReturn[r][v] + pReturn[v][s] < pReturn[r][s])
				{
					pReturn[r][s] = pReturn[r][v] + pReturn[v][s];
				}
			}
		}

		std::cout << v << "-loop\n";
		printMatrix(pReturn, maxVertexCount);
	}

	return pReturn;
}

void LinkedGraph::printMatrix(int** A, int maxNodeCount)
{
	for (auto s = 0; s < maxNodeCount; s++)
	{
		std::cout << "\t" << s;
	}
	std::cout << std::endl;

	for (auto r = 0; r < maxNodeCount; r++)
	{
		std::cout << r << ":\t";
		for (auto s = 0; s < maxNodeCount; s++)
		{
			std::cout << A[r][s] << "\t";
		}
		std::cout << std::endl;
	}
}
