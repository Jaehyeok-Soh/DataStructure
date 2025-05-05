#include "pch.h"
#include "LinkedGraph.h"

int LinkedGraphExample()
{
	LinkedGraph g1 = LinkedGraph(8, GRAPH_UNDIRECTED);

	for (auto i = 0; i < 8; i++)
	{
		g1.addVertexLG(i);
	}

	g1.addEdgeLG(0, 1);
	g1.addEdgeLG(0, 2);
	g1.addEdgeLG(1, 3);
	g1.addEdgeLG(1, 4);
	g1.addEdgeLG(2, 5);
	g1.addEdgeLG(2, 6);
	g1.addEdgeLG(3, 7);
	g1.addEdgeLG(4, 5);

	std::cout << "g1:\n";
	g1.displayLinkedGraph();

	std::cout << "\nDFS traversal:\n";
	g1.traversalDFS(0);

	g1.deleteLinkedGraph();

	return 0;
}
