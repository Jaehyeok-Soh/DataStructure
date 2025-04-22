#pragma once
class ListNode
{
public:
	int data;
	ListNode* pLink;

	~ListNode();
};

class LinkedList
{
public:
	int currentElementCount;
	ListNode headerNode;

public:
	bool addLLElement(int position, ListNode element);
	bool removeLLElement(int position);
	ListNode* getLLElement(int position);

	void clearLinkedList();
	int getLinkedListLength();
	void deleteLinkedList();
	bool isEmpty();

	void DisplayLinkedList();
};