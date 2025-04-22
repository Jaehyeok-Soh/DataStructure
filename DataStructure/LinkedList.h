#pragma once
class ListNode
{
public:
	int data;
	ListNode* pLink;
};

class LinkedList
{
public:
	int currentElementCount;
	ListNode headerNode;

public:
	LinkedList* createLinkedList();
	bool addLLElement(LinkedList* pList, int position, ListNode element);
	bool removeLLElement(LinkedList* pList, int position);
	ListNode* getLLElement(LinkedList* pList, int position);

	void clearLinkedList(LinkedList* pList);
	int getLinkedListLength(LinkedList* pList);
	void deleteLinkedList(LinkedList* pList);
};