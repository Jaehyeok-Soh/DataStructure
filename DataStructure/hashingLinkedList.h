#pragma once
#define HASH_KEY_SIZE 10

struct HashElement
{
	char key[HASH_KEY_SIZE + 1];
	int value;

	bool isEmptyOrDeletedBucket();
	bool isEmptyBucket();
};

struct hashingListNode
{
	HashElement data;
	hashingListNode* next;
};

class hashingLinkedList
{
public:
	int currentElementCount;
	hashingListNode* pHead;
	hashingListNode* pTail;

	bool addLLElement(int position, hashingListNode element);
	bool addLLElementLast(HashElement hashElement);
	bool removeLLElement(int position);
	hashingListNode* getLLElement(int position);

	void clearLinkedList();
	int getLinkedListLength();
	void deleteLinkedList();
};

