#include "pch.h"
#include "LinkedGraph.h"

int GraphSPExample()
{
	LinkedGraph g = LinkedGraph(6, GRAPH_UNDIRECTED);
	int* pResult = nullptr;
	int** A = nullptr;

	for (auto i = 0; i < 6; i++)
	{
		g.addVertexLG(i);
	}

	g.addEdgewithWeightLG(0, 1, 1);
	g.addEdgewithWeightLG(0, 2, 4);
	g.addEdgewithWeightLG(1, 2, 2);
	g.addEdgewithWeightLG(2, 3, 1);
	g.addEdgewithWeightLG(3, 4, 8);
	g.addEdgewithWeightLG(3, 5, 3);
	g.addEdgewithWeightLG(4, 5, 4);
	
	std::cout << "G1:\n";
	g.displayLinkedGraph();

	std::cout << "\nDijkstra:\n";
	pResult = g.shortestPathDijkstra(0);

	std::cout << "\nFloyd:\n";
	A = g.shortestPathFloyd();

	SAFE_DELETE(pResult);
	for (auto i = 0; i < 6; i++)
	{
		SAFE_DELETE_ARRAY(A[i]);
	}
	SAFE_DELETE_ARRAY(A);

	g.deleteLinkedGraph();

	return 0;
}