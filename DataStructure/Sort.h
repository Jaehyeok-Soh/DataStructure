#pragma once
void printArray(int value[], int count);

void selectionSort(int value[], int count);
void selectionExample();

void bubbleSort(int value[], int count);

void insertionSort(int value[], int count);

void heapSort(int value[], int count);

void shellSort(int value[], int count);
void shellInsertionSort(int value[], int start, int end, int interval);

void mergeSort(int value[], int buffer[], int start, int end);
void mergeSortInternal(int value[], int buffer[], int start, int middle, int end);

void quickSort(int value[], int start, int end);
int partitionQuickSort(int value[], int start, int end);