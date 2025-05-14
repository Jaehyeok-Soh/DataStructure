#include "pch.h"
#include "hashingLinkedList.h"

class ChainingHashTable
{
public:
	int bucketSize;
	int currentElementCount;
	hashingLinkedList* pElement;

	ChainingHashTable(int _bucketSize);

	bool addSHT(HashElement element);
	bool deleteElementHT(const char* pKey);
	bool hashFunction(const char* pKey, int bucketSize);
	unsigned int stringToInt(const char* pKey);
	HashElement* searchHT(const char* pKey);
	hashingLinkedList* searchBucket(const char* pKey);
	HashElement* searchSlot(hashingLinkedList* pList, const char* pKey, int* pPosition);
	void deleteHashTable();
	void displayHashTable();
};

ChainingHashTable::ChainingHashTable(int _bucketSize)
{
	if (_bucketSize <= 0)
	{
		bucketSize = 0;
		currentElementCount = 0;
		pElement = nullptr;
		return;
	}

	bucketSize = _bucketSize;
	currentElementCount = 0;
	pElement = new hashingLinkedList[_bucketSize]();
}

bool ChainingHashTable::addSHT(HashElement element)
{
	bool ret = false;

	hashingLinkedList* pList = nullptr;
	pList = searchBucket(element.key);
	if (pList != nullptr)
	{
		pList->addLLElementLast(element);
		currentElementCount++;
		ret = true;
	}
	else
	{
		std::cout << "error, not valid hash address\n";
	}

	return ret;
}

hashingLinkedList* ChainingHashTable::searchBucket(const char* pKey)
{
	hashingLinkedList* pReturn = nullptr;
	int bucketIndex = 0;

	bucketIndex = hashFunction(pKey, bucketSize);
	if (bucketIndex >= 0)
	{
		pReturn = &(this->pElement[bucketIndex]);
	}
	else
	{
		std::cout << "error, not valid hash address\n";
	}

	return pReturn;
}

HashElement* ChainingHashTable::searchHT(const char* pKey)
{
	HashElement* pReturn = nullptr;
	hashingLinkedList* pList = nullptr;
	int position = 0;

	pList = searchBucket(pKey);

	if (pList != nullptr)
	{
		pReturn = searchSlot(pList, pKey, &position);
	}

	return pReturn;
}

HashElement* ChainingHashTable::searchSlot(hashingLinkedList* pList, const char* pKey, int* pPosition)
{
	HashElement* pReturn = nullptr;
	HashElement* pElement = nullptr;

	hashingListNode* pNode = nullptr;
	int position = 0;
	if (pList != nullptr && pPosition != nullptr)
	{
		pNode = pList->getLLElement(0);
		while (pNode != nullptr)
		{
			if (strcmp(pNode->data.key, pKey) == 0)
			{
				pReturn = &(pNode->data);
				*pPosition = position;
				break;
			}
			pNode = pNode->next;
			position++;
		}
		if (pReturn == nullptr)
		{
			std::cout << "error, search fail\n";
		}
	}

	return pReturn;
}

bool ChainingHashTable::hashFunction(const char* pKey, int bucketSize)
{
	int ret = -1;

	unsigned int temp_key = 0;

	if (pKey == nullptr)
	{
		return ret;
	}

	temp_key = stringToInt(pKey);
	if (bucketSize > 0)
	{
		ret = temp_key % bucketSize;
	}

	return ret;
}

unsigned int ChainingHashTable::stringToInt(const char* pKey)
{
	unsigned int ret = 0;
	if (pKey == nullptr)
	{
		return ret;
	}

	while (*pKey != '\0')
	{
		ret = (ret * 31) + (*pKey);
		pKey++;
	}

	return ret;
}

bool ChainingHashTable::deleteElementHT(const char* pKey)
{
	bool ret = false;

	HashElement* pElement = nullptr;
	hashingLinkedList* pList = nullptr;
	int position = 0;
	pList = searchBucket(pKey);
	if (pList != nullptr)
	{
		pElement = searchSlot(pList, pKey, &position);
		if (pElement != nullptr)
		{
			pList->removeLLElement(position);
			currentElementCount--;
			ret = true;
		}
	}

	return ret;
}