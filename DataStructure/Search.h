#pragma once

struct IndexTable
{
	int position;
	int key;
};

int sequentialIndexSearch(int value[], int size, IndexTable index[], int indexSize, int key);
int sequentialRangeSearchAsendingSorted(int value[], int start, int end, int key);
IndexTable* createIndexTable(int value[], int size, int indexSize);