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

	std::cout << "\nBFS traversal:\n";
	g1.traversalBSF(0);

	g1.deleteLinkedGraph();

	//mst
	std::cout << std::endl;

	LinkedGraph g2 = LinkedGraph(6, GRAPH_UNDIRECTED);
	for (auto i = 0; i < 6; i++)
	{
		g2.addVertexLG(i);
	}

	g2.addEdgewithWeightLG(0, 1, 4);
	g2.addEdgewithWeightLG(0, 2, 3);
	g2.addEdgewithWeightLG(1, 2, 2);
	g2.addEdgewithWeightLG(2, 3, 1);
	g2.addEdgewithWeightLG(3, 4, 1);
	g2.addEdgewithWeightLG(3, 5, 5);
	g2.addEdgewithWeightLG(4, 5, 6);

	std::cout << "g1:\n";
	g2.displayLinkedGraph();

	std::cout << "\nPrim MST:\n";
	LinkedGraph* pMST1 = g2.mstPrim(1);
	pMST1->displayLinkedGraph();

	g2.deleteLinkedGraph();
	pMST1->deleteLinkedGraph();

	return 0;
}
