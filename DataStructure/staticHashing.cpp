#include "pch.h"
#define HASH_KEY_SIZE 30
enum HashElementStatus
{
	EMPTY = 0,
	USED_HASH,//USED
	DELETED,
};

struct HashElement
{
	char key[HASH_KEY_SIZE + 1];
	int value;
	HashElementStatus status;

	bool isEmptyOrDeletedBucket();
	bool isEmptyBucket();
};

class HashTable
{
public:
	int bucketSize;
	int currentElementCount;
	HashElement* pElement;

	HashTable(int _bucketSize);

	bool addElementSHT(HashElement element);
	int hashFunction(const char* pKey, int bucketSize);
	unsigned int stringToInt(const char* pKey);
	HashElement* searchHT(const char* pKey);
	bool deleteElementHT(const char* pKey);
	void deleteHashTable();
};

HashTable::HashTable(int _bucketSize)
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
	pElement = new HashElement[_bucketSize]();
}

bool HashTable::addElementSHT(HashElement element)
{
	bool ret = false;
	HashElement* pElement = nullptr;
	int bucketIndex = 0;
	int tempIndex = 0;
	int inc = 1;

	if (this->pElement == nullptr)
	{
		ret = false;
		return ret;
	}

	bucketIndex = hashFunction(element.key, this->bucketSize);
	if (bucketIndex < 0 || bucketIndex >= this->bucketSize)
	{
		ret = false;
		return ret;
	}

	tempIndex = bucketIndex;
	do
	{
		pElement = &(this->pElement[tempIndex]);
		if (pElement->isEmptyOrDeletedBucket() == true)
		{
			this->pElement[tempIndex] = element;
			this->pElement[tempIndex].status = USED_HASH;
			ret = true;
			break;
		}
		else
		{
			if (strcmp(pElement->key, element.key) == 0)
			{
				ret = false;
				break;
			}
			else
			{
				tempIndex = (tempIndex + inc) % this->bucketSize;
				if (tempIndex == bucketIndex)
				{
					ret = false;
					break;
				}
			}
		}
	} while (tempIndex != bucketIndex);

	return ret;
}

int HashTable::hashFunction(const char* pKey, int bucketSize)
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

unsigned int HashTable::stringToInt(const char* pKey)
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

HashElement* HashTable::searchHT(const char* pKey)
{
	HashElement* pReturn = nullptr;
	HashElement* pElement = nullptr;

	int bucketIndex = 0;
	int tempIndex = 0;
	int inc = 1;

	bucketIndex = hashFunction(pKey, bucketSize);
	if (bucketIndex < 0)
	{
		pReturn = nullptr;
		return pReturn;
	}

	tempIndex = bucketIndex;
	do
	{
		pElement = &(this->pElement[tempIndex]);
		if (pElement->isEmptyBucket() == true)
		{
			pReturn = nullptr;
			break;
		}
		else
		{
			if (pElement->status == USED_HASH && strcmp(pElement->key, pKey) == 0)
			{
				pReturn = pElement;
				break;
			}
			else
			{
				tempIndex = (tempIndex + 1) % this->bucketSize;
				if (tempIndex == bucketIndex)
				{
					pReturn = nullptr;
					break;
				}
			}
		}

	} while (tempIndex != bucketIndex);

	return pReturn;
}

bool HashTable::deleteElementHT(const char* pKey)
{
	bool ret = false;
	HashElement* pElement = nullptr;
	int bucketIndex = 0;
	int tempIndex = 0;
	int inc = 1;
	
	pElement = searchHT(pKey);
	if (pElement != nullptr)
	{
		pElement->status = DELETED;
		pElement->key[0] = '\0';
		pElement->value = 0;
		ret = true;
	}
	else
	{
		std::cout << "error\n";
	}

	return ret;
}

void HashTable::deleteHashTable()
{
	SAFE_DELETE_ARRAY(pElement);
}

bool HashElement::isEmptyOrDeletedBucket()
{
	int ret = false;

	if (status == EMPTY || status == DELETED)
	{
		ret = true;
	}

	return ret;
}

bool HashElement::isEmptyBucket()
{
	bool ret = false;
	if (status == EMPTY)
	{
		ret = true;
	}

	return false;
}

int StaticHashingExample()
{
	HashTable hashTable = HashTable(13);
	
	HashElement element1 = { "january", 1 };
	HashElement element12 = { "december", 12 };

	HashElement* pElement = nullptr;
	HashElement* pElement2 = nullptr;

	hashTable.addElementSHT(element1);
	hashTable.addElementSHT(element12);

	std::cout << "hash table\n";
	//hashTable.displayHashTable();

	pElement = hashTable.searchHT("april");
	if (pElement != nullptr)
	{
		std::cout << "search key : " << pElement->key << "search result : " << pElement->value << std::endl;
		hashTable.deleteElementHT("april");
		
		std::cout << "april delete\n";
		pElement2 = hashTable.searchHT("april");
		if (pElement != nullptr)
		{
			std::cout << "search key : " << pElement2->key << "search result : " << pElement2->value << std::endl;
		}
		
		pElement2 = hashTable.searchHT("june");
		if (pElement != nullptr)
		{
			std::cout << "search key : " << pElement2->key << "search result : " << pElement2->value << std::endl;
		}
	}

	hashTable.deleteHashTable();

	return 0;
}