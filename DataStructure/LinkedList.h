#pragma once

typedef struct ListNodeType
{
	int data;
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

	void iterateLinkedList();
	void concatLinkedList(LinkedList* pList);
	void reverseLinkedList();
};