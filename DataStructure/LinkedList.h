#pragma once

typedef struct ListNodeType
{
	int data;
	float coef; 
	int degree; 
	
	ListNodeType* pLink;
} ListNode;

class LinkedList
{
private:
	int currentElementCount;
	ListNode headerNode;

public:
	LinkedList();
	~LinkedList();

	bool addLLElement(int position, ListNode element);
	bool removeLLElement(int position);
	ListNode* getLLElement(int position);

	void clearLinkedList();
	void deleteLinkedList();
	bool isEmpty();

	void DisplayLinkedList();

	//Op
	void iterateLinkedList();
	void concatLinkedList(LinkedList* pList);
	void reverseLinkedList();
	//Poly
	bool addPolyNodeLast(float coef, int degree);
	bool addPolyNodeLast(LinkedList* pList, float coef, int degree);
	LinkedList* polyAdd(LinkedList* pList);
	void displayPolyList();
	void displayPolyList(LinkedList* pList);
};