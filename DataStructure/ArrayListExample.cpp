#include "pch.h"

int ArrayListExample()
{
	int i = 0;
	int arrayCount = 0;
	ArrayList* pList = nullptr;
	ArrayListNode* pValue = nullptr;
	
	pList = createArrayList(6);
	if (pList)
	{
		ArrayListNode node;
		
		node.data = 1;
		addALElement(pList, 0, node);

		node.data = 3;
		addALElement(pList, 1, node);

		node.data = 5;
		addALElement(pList, 2, node);
		displayArrayList(pList);

		removeALElement(pList, 0);
		displayArrayList(pList);

		arrayCount = getArrayListLength(pList);
		for (i = 0; i < arrayCount; i++)
		{
			pValue = getALElement(pList, i);
			std::cout << "position " << i << '-' << pValue->data << std::endl;
		}

		deleteArrayList(pList);
	}

	return 0;
}