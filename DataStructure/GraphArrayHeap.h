#pragma once
class GraphHeapNode
{
public:
	int key = 0;
	int fromVertexID = 0;
	int toVertexID = 0;

	GraphHeapNode() = default;
	GraphHeapNode(int _key, int _fromVertexID, int _toVertexID);
};

//arrayMaxHeap, arrayMinHeap
class GraphArrayHeap
{
public:
	int maxElementCount = 0;
	int currentElementCount = 0;
	GraphHeapNode* pElement = nullptr;

	GraphArrayHeap() = default;
	GraphArrayHeap(int elementCount);
	virtual ~GraphArrayHeap();

	void displayArrayHeap();
};

class GraphArrayMaxHeap : public GraphArrayHeap
{
public:
	GraphArrayMaxHeap(int elementCount) : GraphArrayHeap(elementCount) {};
	~GraphArrayMaxHeap() override;

	void deleteArrayMaxHeap();
	void insertMaxHeapAH(GraphHeapNode element);
	GraphHeapNode* deleteMaxHeapAH();
};

class GraphArrayMinHeap : public GraphArrayHeap
{
public:
	GraphArrayMinHeap(int elementCount) : GraphArrayHeap(elementCount) {};
	~GraphArrayMinHeap() override;

	void deleteArrayMinHeap();
	void insertMinHeapAH(GraphHeapNode element);
	GraphHeapNode* deleteMinHeapAH();
};