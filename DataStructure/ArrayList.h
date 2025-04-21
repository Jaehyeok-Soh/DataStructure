#pragma once
typedef struct ArrayListNodetype
{
	int data;
} ArrayListNode;

typedef struct ArrayListType
{
	int maxElementCount;
	int currentElementCount;
	ArrayListNode* pElement;
} ArrayList;

ArrayList* createArrayList(int maxElementCount);
void deleteArrayList(ArrayList* pList);
bool isArrayListPull(ArrayList* pList);
bool addALElement(ArrayList* pList, int position, ArrayListNode element);
bool removeALElement(ArrayList* pList, int position);
ArrayListNode* getALElement(ArrayList* pList, int position);
void displayArrayList(ArrayList* pList);
void clearArrayLIst(ArrayList* pList);
int getArrayListLength(ArrayList* pList);