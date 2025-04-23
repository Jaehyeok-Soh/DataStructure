#pragma once
class DoublyListNode
{
public:
	int data;
	DoublyListNode* prev;
	DoublyListNode* next;

	DoublyListNode();
	DoublyListNode(int _data);
	~DoublyListNode();
};

class DoublyList
{
private:
	int currentElementCount;

public:
	DoublyList();
	~DoublyList();

	DoublyListNode* pHead;
	DoublyListNode* pTail;

	bool addDLElement(int position, int data);
	bool removeDLElement(int position);
	void clearDoublyList();
	DoublyListNode* getDLElement(int position);
	void displayDoublyList();
};