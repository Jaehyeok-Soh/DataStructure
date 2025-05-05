#include "pch.h"
#include "ArrayGraph.h"

int GraphExample()
{
	ArrayGraph g1 = ArrayGraph(6, GRAPH_UNDIRECTED);
	ArrayGraph g2 = ArrayGraph(6, GRAPH_DIRECTED);
	ArrayGraph g4 = ArrayGraph(6, GRAPH_DIRECTED);

	for (auto i = 0; i < 6; i++)
	{
		g1.addVertexAG(i);
		g2.addVertexAG(i);
		g4.addVertexAG(i);
	}

	g1.addEdgeAG(0, 1);
	g1.addEdgeAG(0, 2);
	g1.addEdgeAG(1, 2);
	g1.addEdgeAG(2, 3);
	g1.addEdgeAG(3, 4);
	g1.addEdgeAG(3, 5);
	g1.addEdgeAG(4, 5);

	g2.addEdgeAG(0, 1);
	g2.addEdgeAG(1, 2);
	g2.addEdgeAG(2, 0);
	g2.addEdgeAG(2, 1);
	g2.addEdgeAG(2, 3);
	g2.addEdgeAG(3, 2);
	g2.addEdgeAG(3, 4);
	g2.addEdgeAG(4, 5);
	g2.addEdgeAG(5, 3);

	g4.addEdgewithWeightAG(0, 1, 4);
	g4.addEdgewithWeightAG(1, 2, 1);
	g4.addEdgewithWeightAG(2, 0, 2);
	g4.addEdgewithWeightAG(2, 1, 3);
	g4.addEdgewithWeightAG(2, 3, 2);
	g4.addEdgewithWeightAG(3, 2, 1);
	g4.addEdgewithWeightAG(3, 4, 1);
	g4.addEdgewithWeightAG(4, 5, 1);
	g4.addEdgewithWeightAG(5, 3, 2);

	std::cout << "g1: undirected\n";
	g1.displayArrayGraph();
	std::cout << "\ng2:directed\n";
	g2.displayArrayGraph();
	std::cout << "\ng3:directed weight\n";
	g4.displayArrayGraph();

	g1.deleteArrayGraph();
	g2.deleteArrayGraph();
	g4.deleteArrayGraph();

	return 0;
}